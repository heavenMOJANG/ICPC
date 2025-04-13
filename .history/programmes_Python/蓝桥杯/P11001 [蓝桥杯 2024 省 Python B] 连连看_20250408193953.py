n, m = map(int, input().split())
a, g =[], [[] for i in range(1001)] 
for i in range(n):
    data = list(map(int, input().split()))
    a.append(data)
    for j in range(m):
        g[data[j]].append((i, j))
ans = 0
d = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
for i in range(1001):
    if len(g[i]) > 1:
        for pair in g[i]:
            x, y = pair
            while True:
                x += 1
                y += 1
                if x >= n or y >= m:
                    break
                if a[x][y] != i:
                    break
                ans += 1
print(ans)
