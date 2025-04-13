n, m = map(int, input().split())
a = list(map(int, input().split()))
N = int(2e6 + 10)
l = [0 for _ in range(N)]
r = [0 for _ in range(N)]
for x in range(n):
    if x < 0:
        l[-x] += 1
    else:
        r[x] += 1
for i in range(1, m + 1):
    l[i] += l[i - 1]
    r[i] += r[i - 1]
ans = 0
for i in range(1, m + 1):
    res = l[i]
    if m - 2 * i > 0:
        res += r[m - i * 2]
    ans = max(ans, res)
for i in range(1, m + 1):
    res = r[i]
    if m - 2 * i > 0:
        res += l[m - i * 2]
    ans = max(ans, res)
for x in a:
    if x == 0:
        ans += 1
print(ans)