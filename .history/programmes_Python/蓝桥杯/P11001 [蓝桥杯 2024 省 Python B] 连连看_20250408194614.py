n, m = map(int, input().split())
a, g =[], [[] for i in range(1001)] 
for i in range(n):
    data = list(map(int, input().split()))
    a.append(data)
ans = 0
l = [[0] * 2001 for i in range(2001)]
r = [[0] * 2001 for i in range(2001)]
for i in range(n):
    for j in range(m):
        ans += l[i + j][a[i][j]] + r[i - j][a[i][j]]
        l[i + j][a[i][j]] += 1
        r[i - j][a[i][j]] += 1
print(ans)
