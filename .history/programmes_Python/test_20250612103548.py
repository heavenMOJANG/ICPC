class DSU:
    def __init__(self):
        self.n = 0
        self.top = 0
        self.fa = [i for i in range(300001)]
        self.sz = [0] * 300000
        self.st = [0] * 300000
    def ins(self):
        self.n += 1
        self.fa[self.n] = self.n
        self.sz[self.n] = 1
    def find(self, x):
        if self.fa[x] == x: return x
        else: self.fa[x] = self.findSet(self.fa[x])
    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y: return
        if self.sz[x] < self.sz[y]: x, y = y, x
        self.top += 1
        self.st[self.top] = y
        self.fa[y] = x
        self.sz[x] += self.sz[y]
    def dele(self):
        if self.top == 0: return
        y = self.st[self.top]
        self.top -= 1
        self.sz[self.fa[y]] -= self.sz[y]
        self.fa[y] = y