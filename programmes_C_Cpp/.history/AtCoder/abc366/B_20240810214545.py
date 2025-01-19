N = int(input())
S = [input() for _ in range(N)]
M = max(len(s) for s in S)
T = ['*' * N for _ in range(M)]
for i, s in enumerate(S):
    for j, char in enumerate(s):
        T[j] = T[j][:N-i-1] + char + T[j][N-i:]
T = [t.rstrip('*') for t in T]
for t in T:
    print(t)