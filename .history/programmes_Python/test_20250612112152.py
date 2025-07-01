n = int(input())
ans = 0
a = [0] * 1048577
b = [0] * 1048577
for i in range(1, n + 1):
    for j in range(i, n + 1, i):
        a[j] += 1
for i in range(1, n + 1):
    b[i] = b[i - 1] + a[i]
for i in range(1, n + 1):
    ans += a[i] * b[n - i]
print(ans)