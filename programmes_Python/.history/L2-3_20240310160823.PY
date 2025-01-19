n = int(input())
a = [1 for i in range(0, n + 1)]
G = {}
cnt = 0
to = [0 for i in range(200010)]
nxt = [0 for i in range(200010)]
head = [-1 for i in range(200010)]
depth = [0 for i in range(200010)]
def addEdge(u, v):
    global cnt
    to[cnt] = v
    nxt[cnt] = head[u]
    head[u] = cnt
    cnt += 1
def dfs(x):
    u = head[x]
    while True:
        if u == -1:
            break
        v = to[u]
        depth[v] = depth[x] + 1
        dfs(v)
        u = nxt[u]
    return
for i in range(1,n + 1):
    d = list(map(int, input().split()))
    k = d[0]
    for j in range(1, k + 1):
        a[d[j]] = 0
        addEdge(i, j)
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