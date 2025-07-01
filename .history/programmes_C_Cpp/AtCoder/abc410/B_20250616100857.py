n, q = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * n
for x in a:
    if x >= 1:
        b[x - 1] += 1
    else:
        p = -1, minn = 1000
        for i in range(n):
            if b[i] < minn:
                minn = b[i]
                p = i
        b[p] += 1
print(" ".join(b))