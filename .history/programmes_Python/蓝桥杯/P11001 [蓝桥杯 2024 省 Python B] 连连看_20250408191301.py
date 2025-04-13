n, m = map(int, input().split())
g = [[] for i in range(1001)] 
for i in range(n):
    data = list(map(int, input().split()))
    for j in range(m):
        g[data[j]].append((i, j))
ans = 0
for i in range(1001):
    if len(g[i]) > 1:
        ans += len(g[i]) * (len(g[i]) - 1)
print(ans)
