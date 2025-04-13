N, M, L, R = map(int, input().split())
edges = []
fa = [i for i in range(N + 1)]
siz = [1] * (N + 1)
def findSet(x):
    return x if fa[x] == x else findSet(fa[x])
def unionSet(fx, fy):
    x = findSet(fx), y = findSet(fy)
    if x == y:
        return False
    if siz[x] < siz[y]:
        fa[x] = y
        siz[y] += siz[x]
    else:
        fa[y] = x
        siz[x] += siz[y]
    return True
for i in range(M):
    a, b, c = map(int, input().split())
    if c < L or c > R:
        continue
    edges.append((a, b, c))
ans = 0
for u, v, w in sorted(edges, key = lambda x: x[2]):
    fu, fv = findSet(u), findSet(v)
    res = siz[fu] * siz[fv]
    if unionSet(u, v):
        ans += res
print(ans)