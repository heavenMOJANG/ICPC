from collections import deque
def bfs(n, g, d, h):
    dq = deque()
    d[0][0] = 0
    dq.append((0, 0))
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
        if d[n - 1][n - 1] != -1:
            print(d[n - 1][n - 1])
            return
    return
def main():
    N = 1010
    n = int(input())
    g = []
    for i in range(n):
        g.append(list(map(int, input().split())))
    h = [[[0, 0] for j in range(N)] for i in range(N)]
    for i in range(n):
        h[i][1][0] = 0
        for j in range(1, n):
            h[i][j][0] = h[i][j - 1][0] if g[i][j] > g[i][j - 1] else j
        h[i][n - 1][1] = n - 1
        for j in range(n - 2, -1, -1):
            h[i][j][1] = h[i][j + 1][1] if g[i][j] > g[i][j + 1] else j
    d = [[-1 for j in range(N)] for i in range(N)]
    bfs(n, g, d, h)
main()