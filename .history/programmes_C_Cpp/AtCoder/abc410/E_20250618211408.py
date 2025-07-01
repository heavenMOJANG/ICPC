N, H, M = map(int, input().split())
dp = [[-1] * 6001] * 3001
dp[0][M] = H
ans = 0
for i in range(N):
    A, B = map(int, input().split())
    for j in range(0, M - B):
        dp[i][j] = max(dp[i - 1][j] - A, dp[i - 1][j + B])
        if dp[i][j] >= 0:
            ans = i + 1
print(ans)