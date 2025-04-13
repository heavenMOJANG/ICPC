N, M, L, R = map(int, input().split())
edges = []
fa = [i for i in range(N + 1)]
siz = [1] * (N + 1)
def findSet(x):
    return x if fa[x] == x else findSet(fa[x])
def unionSet(x, y):
    x = findSet(x), y = findSet(y)
    if x == y:
        return
    if siz[x] < siz[y]:
        fa[x] = y
        siz[y] += siz[x]
    else:
        fa[y] = x
        siz[x] += siz[y]
for i in range(M):
    a, b, c = map(int, input().split())
    if c < L or c > R:
        continue
    edges.append((a, b, c))