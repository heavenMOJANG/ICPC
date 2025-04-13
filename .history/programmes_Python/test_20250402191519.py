def dfs(u, g, isRt, tmp, ans):
    if len(tmp) > len(ans[0]):
        ans[0] = tmp[:]
    for v in g[u]:
        tmp.append(v)
        dfs(v, g, isRt, tmp, ans)
        tmp.pop()
def proc(n, edges):
    g = [[] for _ in range(n)]
    isRt = [True] * n
    for edge in edges:
        u, v = edge
        g[u].append(v)
        isRt[v] = False
    for i in range(n):
        g[i].sort()
    ans = [[]]
    for i in range(n):
        if isRt[i]:
            tmp = [i]
            dfs(i, g, isRt, tmp, ans)
    return len(ans[0]), ans[0]
n = int(input())
edges = []
for i in range(n):
    inp = list(map(int, input().split()))
    k = inp[0]
    for j in range(1, k + 1):
        edges.append((i, inp[j]))
length, path = proc(n, edges)
print(length)
print(' '.join(map(str, path)))
