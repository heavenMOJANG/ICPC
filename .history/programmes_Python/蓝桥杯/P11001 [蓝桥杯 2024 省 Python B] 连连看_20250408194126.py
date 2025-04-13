n, m = map(int, input().split())
a, g =[], [[] for i in range(1001)] 
for i in range(n):
    data = list(map(int, input().split()))
    a.append(data)
    for j in range(m):
        g[data[j]].append((i, j))
ans = 0
for i in range(1001):
    if len(g[i]) > 1:
        for pair in g[i]:
            x, y, cnt = pair, 0
            while True:
                x += 1
                y += 1
                if x >= n or y >= m:
                    break
                if a[x][y] == i:
                    cnt += 1
            ans += cnt
            x, y, cnt = pair, 0
            while True:
                x -= 1
                y -= 1
                if x < 0 or y < 0:
                    break
                if a[x][y] == i:
                    cnt += 1
            ans += cnt
            x, y, cnt = pair, 0
            while True:
                x += 1
                y -= 1
                if x >= n or y < 0:
                    break
                if a[x][y] == i:
                    cnt += 1
            ans += cnt
            x, y, cnt = pair, 0
            while True:
                x -= 1
                y += 1
                if x < 0 or y >= m:
                    break
                if a[x][y] == i:
                    cnt += 1
            ans += cnt
print(ans)
