N, M = map(int, input().split())
sum = 0
for i in range(N):
    a, b = map(int, input().split())
    sum += a * pow(2, b)
    