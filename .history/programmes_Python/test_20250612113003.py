n = int(input())
p = [0] + list(map(int, input().split()))
a = []
vis = [0] * (n + 1)
for i in range(1, n + 1):
