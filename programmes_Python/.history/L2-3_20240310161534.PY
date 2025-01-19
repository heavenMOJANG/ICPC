n = int(input())
a = [1 for i in range(0, n + 1)]
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
def dfs(u):
    i = head[u]
    while True:
        if i == -1:
            break
        v = to[i]
        depth[v] = depth[u] + 1
        dfs(v)
        i = nxt[i]
    return
for i in range(1,n + 1):
    d = list(map(int, input().split()))
    k = d[0]
    for j in range(1, k + 1):
        a[d[j]] = 0
        addEdge(i, d[j])
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