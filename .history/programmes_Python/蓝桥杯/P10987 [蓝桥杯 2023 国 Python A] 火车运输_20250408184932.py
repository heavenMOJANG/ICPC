N, A, B = map(int, input().split())
dp = [[0] * (B + 1)] * (A + 1)
w = list(map(int, input().split()))
maxn = 0
for i in range(N):
    for j in range(A, A - w[i] - 1, -1):
        for k in range(B, B - w[i] -1, -1):
            dp[j][k] = max(dp[j][k], dp[j - w[i]][k] + w[i], dp[j][k - w[i]] + w[i])
            maxn = max(maxn, dp[j][k])
print(maxn)