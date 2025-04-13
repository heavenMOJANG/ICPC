N, M, L, R = map(int, input().split())
edges = []
fa = [i for i in range(N + 1)]
siz = [1] * (N + 1)
for i in range(M):
    a, b, c = map(int, input().split())
    if c < L or c > R:
        continue
    edges.append((a, b, c))