class DSU:
    def __init__(self):
        self.top = -1
        self.fa = [i for i in range(300001)]
        self.sz = [1] * 300001
        self.st = [0] * 300000
    def find(self, x):
        if self.fa[x] != x: self.fa[x] = self.find(self.fa[x])
        return self.fa[x]
    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y: return
        if self.sz[x] < self.sz[y]: x, y = y, x
        self.top += 1
        self.st[self.top] = y
        self.fa[y] = x
        self.sz[x] += self.sz[y]
    def dele(self):
        if self.top == -1: return
        y = self.st[self.top]
        self.top -= 1
        self.sz[self.fa[y]] -= self.sz[y]
        self.fa[y] = y
dsu = DSU()
n, m = map(int, input().split())
for i in range(m):
    inp = list(map(int, input().split()))
    if inp[0] == 1:
        dsu.union(inp[1], inp[2])
    if inp[0] == 2:
        dsu.dele()
    if inp[0] == 3:
        if dsu.find(inp[1]) == dsu.find(inp[2]): print("Yes")
        else: print("No")