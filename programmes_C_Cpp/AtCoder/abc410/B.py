n, q = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * n
ans = []
for x in a:
    if x >= 1:
        b[x - 1] += 1
        ans.append(x)
    else:
        p, minn = -1, 1000
        for i in range(n):
            if b[i] < minn:
                minn = b[i]
                p = i
        b[p] += 1
        ans.append(p + 1)
print(*ans, sep = " ")