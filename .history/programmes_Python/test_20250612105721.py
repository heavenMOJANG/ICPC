class DSU:
    def __init__(self, n):
        self.fa = [i for i in range(n + 1)]
        self.sz = [1] * (n + 1)
        self.stack = []

    def find(self, x):
        while x != self.fa[x]:
            x = self.fa[x]
        return x

    def union(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if fx == fy:
            self.stack.append((-1, -1))  # 占位，表示没有真正合并
            return
        if self.sz[fx] < self.sz[fy]:
            fx, fy = fy, fx
        self.stack.append((fy, self.sz[fx]))  # 记录被合并的集合和原本 fx 的大小
        self.fa[fy] = fx
        self.sz[fx] += self.sz[fy]

    def rollback(self):
        if not self.stack:
            return
        fy, old_sz = self.stack.pop()
        if fy == -1:
            return  # 无合并发生，直接返回
        fx = self.fa[fy]
        self.sz[fx] = old_sz
        self.fa[fy] = fy

# 读入与处理主逻辑
n, m = map(int, input().split())
dsu = DSU(n)

results = []

for _ in range(m):
    parts = input().split()
    if parts[0] == '1':
        x, y = int(parts[1]), int(parts[2])
        dsu.union(x, y)
    elif parts[0] == '2':
        dsu.rollback()
    elif parts[0] == '3':
        x, y = int(parts[1]), int(parts[2])
        if dsu.find(x) == dsu.find(y):
            results.append("Yes")
        else:
            results.append("No")

print("\n".join(results))
