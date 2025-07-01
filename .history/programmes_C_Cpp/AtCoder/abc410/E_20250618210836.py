N, H, M = map(int, input().split())
dp = [[0] * 6001] * 3001
dp[0][M] = H
for i in range(N):
    A, B = map(int, input().split())
    for