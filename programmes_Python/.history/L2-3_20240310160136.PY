n = int(input())
a = [1 for i in range(0, n + 1)]
G = {}
depth = [0 for i in range(0, n + 1)]
def dfs(x):
    for i in G[x]:
        depth[i] = depth[x] + 1
        dfs(i)
    return
for i in range(1, n + 1):
    G[i] = []
for i in range(1,n + 1):
    d = list(map(int, input().split()))
    k = d[0]
    for j in range(1, k + 1):
        a[d[j]] = 0
        G[i].append(d[j])
root = 0
for i in range(1, n + 1):
    if a[i]:
        root = i
depth[root] = 1
dfs(root)
maxn, idx = 0, 0
for i in range(1, n + 1):
    if depth[i] > maxn:
        maxn = depth[i]
        idx = i
print(idx)