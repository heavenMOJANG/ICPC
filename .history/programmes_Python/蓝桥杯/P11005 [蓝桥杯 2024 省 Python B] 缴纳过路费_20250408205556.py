N, M, L, R = map(int, input().split())
edges = []
fa = [i for i in range(N + 1)]
siz = [1] * (N + 1)
def findSet(x):
    return x if fa[x] == x else findSet(fa[x])
def unionSet(x, y):
    fx, fy = findSet(x), findSet(y)
    if fx == fy:
        return False
    if siz[fx] < siz[fy]:
        fa[fx] = fy
        siz[fy] += siz[fx]
    else:
        fa[fy] = fx
        siz[fx] += siz[fy]
    return True
for i in range(M):
    a, b, c = map(int, input().split())
    if c < L or c > R:
        continue
    edges.append((a, b, c))
ans = 0
for u, v, w in sorted(edges, key = lambda x: x[2], reverse = True):
    fu, fv = findSet(u), findSet(v)
    res = siz[fu] * siz[fv]
    if unionSet(u, v) == True:
        ans += res
print(ans)