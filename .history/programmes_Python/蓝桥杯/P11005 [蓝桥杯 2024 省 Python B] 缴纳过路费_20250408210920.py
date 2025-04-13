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
    u, v, w = map(int, input().split())
    if w < L or w > R:
        continue
    edges.append((w, u, v))
ans = 0
for w, u, v in sorted(edges, reverse = True):
    fu, fv = findSet(u), findSet(v)
    res = siz[fu] * siz[fv]
    if unionSet(u, v) == True:
        ans += res  
print(ans)