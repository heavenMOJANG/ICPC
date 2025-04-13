from collections import deque
def bfs(N, g, d, h):
    dq = deque()
    for i in range(N):
        for j in range(N):
            d[i][j] = -1
    d[0][0] = 0
    while len(dq):
        r, c = map(int, dq.popleft())
        if d[r + 1][c] == -1:
            dq.append((r + 1, c))
            d[r + 1][c] = d[r][c] + 1
        if d[r][c + 1] == -1:
            dq.append((r, c + 1))
            d[r][c + 1] = d[r][c] + 1
        for i in range(h[r][c][0], h[r][c][1] + 1):
            if d[r][i] == -1:
                dq.append((r, i))
                d[r][i] = d[r][c] + 1
        if d[N - 1][N - 1] != -1:
            print(d[N - 1][N - 1])
            return
    return
def main():
    N = int(input())
    g = []
    for i in range(N):
        row = list(map(int, input().split()))
    h = [[[0, 0] for j in range(N + 1)] for i in range(N + 1)]
    for i in range(N):
        h[i][1][0] = 0
        for j in range(1, N):
            h[i][j][0] = h[i][j - 1][0] if g[i][j] > g[i][j - 1] else j
        h[i][N - 1][1] = N - 1
        for j in range(N - 2, -1, -1):
            h[i][j][1] = h[i][j + 1][1] if g[i][j] > g[i][j + 1] else j
    d = [[0 for j in range(N)] for i in range(N)]
    bfs(N, g, d, h)
#if "__name__" == "__main__":
main()