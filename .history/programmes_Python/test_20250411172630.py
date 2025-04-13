N = 1 * 10 ** 5 + 10
n, m = map(int, input().split())
g = [[] for i in range(N)]
a = [0] + list(map(int, input().split()))
dfn = [0] * N
siz = [1] * N
tr = [0] * N
idx = 0
def lowbit(x):
    return x & -x
def update(x, d):
    global tr
    while x <= n:
        tr[x] += d
        x += lowbit(x)
def query(x):
    global tr
    res = 0
    while x > 0:
        res += tr[x]
        x -= lowbit(x)
    return res
def get(l, r):
    return query(r) - query(l - 1)
def dfs(u, f):
    global g, dfn
    global siz
    global idx
    idx += 1
    dfn[u] = idx
    for v in g[u]:
        if v == f: continue
        dfs(v, u)
        siz[u] += siz[v]
for i in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
dfs(1, -1)
for i in range(1, n + 1):
    update(dfn[i], a[i])
for i in range(m):
    op = list(map(int, input().split()))
    if len(op) == 3:
        d = op[2] - a[op[1]]
        update(dfn[op[1]], d)
    else:
        print(get(dfn[op[1]], dfn[op[1]] + siz[op[1]] - 1))