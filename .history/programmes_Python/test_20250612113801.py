n = int(input())
a = [0] + list(map(int, input().split()))
prex = [[0] * 21] * (n + 1)
prea = [0] * (n + 1)
for i in range(1, n + 1):
    for j in range(0, 21):