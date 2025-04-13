from collections import deque
def bfs(N, g, d, h):
    return
def main():
    N = int(input())
    g = []
    for i in range(N):
        row = list(map(int, input().split()))
    h = [[[0, 0] for j in range(N + 1)] for i in range(N + 1)]
    for i in range(N):
        h[i][1][0] = 1
        for j in range(1, N):
            h[i][j][0] = h[i][j - 1][0] if g[i][j] > g[i][j - 1] else j
        h[i][N - 1][1] = N - 1
        for j in range(N - 2, -1, -1):
            h[i][j][1] = h[i][j + 1][1] if g[i][j] > g[i][j + 1] else j
    bfs(N, g, d, h)
if "__name__" == "__main__":
    main()