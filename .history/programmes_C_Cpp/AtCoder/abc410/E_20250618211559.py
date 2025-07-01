N, H, M = map(int, input().split())
dp = [[-1] * (M + 1)] * (N + 1)
dp[0][M] = H
ans = 0
for i in range(1, N + 1):
    A, B = map(int, input().split())
    for j in range(0, M - B + 1):
        dp[i][j] = max(dp[i - 1][j] - A, dp[i - 1][j + B])
        if dp[i][j] >= 0:
            ans = i
print(ans)