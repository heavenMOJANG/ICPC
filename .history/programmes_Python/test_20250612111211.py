n = int(input())
h = [0] + list(map(int, input().split()))
ans = 1
for d in range(1, n):
    for l in range(1, d + 1):
        cnt = 1
        for x in range(l + d, n + 1, d):
            if h[x] > h[x - d]:
                cnt += 1
                ans = max(ans, cnt)
            else: cnt = 1
print(ans)