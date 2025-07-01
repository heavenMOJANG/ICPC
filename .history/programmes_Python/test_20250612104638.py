class DSU:
    def __init__(self):
        self.top = -1
        self.fa = [i for i in range(300001)]
        self.sz = [1] * 300001  # 初始每个集合大小为1
        self.st = [0] * 300000  # 用于记录撤销操作的栈

    def find(self, x):
        if self.fa[x] != x:
            self.fa[x] = self.find(self.fa[x])
        return self.fa[x]  # ❗️必须返回结果

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self.sz[x] < self.sz[y]:
            x, y = y, x  # 保证 x 是更大的集合
        self.top += 1
        self.st[self.top] = y  # 记录被合并的集合
        self.fa[y] = x
        self.sz[x] += self.sz[y]

    def dele(self):
        if self.top == -1:
            return
        y = self.st[self.top]
        self.top -= 1
        x = self.fa[y]
        self.sz[x] -= self.sz[y]
        self.fa[y] = y  # 撤销时把 y 恢复为自己的父亲

# ------------------------------
# 主程序逻辑
dsu = DSU()
n, m = map(int, input().split())

for _ in range(m):
    inp = list(map(int, input().split()))
    if inp[0] == 1:
        dsu.union(inp[1], inp[2])
    elif inp[0] == 2:
        dsu.dele()
    elif inp[0] == 3:
        if dsu.find(inp[1]) == dsu.find(inp[2]):  # ❗️应使用 find
            print("Yes")
        else:
            print("No")
