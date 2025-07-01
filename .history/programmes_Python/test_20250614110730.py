N = int(1e6 + 10)
tr = [0] * N
n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
def lowbit(x):
    return x & -x
def update(p, d):
    while p <= n:
        tr[p] += d
        p += lowbit(p)
def query(p):
    res = 0
    while p > 0:
        res += tr[p]
        p -= lowbit(p)
    return res
for i in range(1, n + 1):
    update(i, a[i])
for testcase in range(m):
    data = list(map(int, input().split()))
    if data[0] == 1:
        p, d = map(int, data[1:3])
        update(p, d)
    else:
        l , r = map(int, data[1:3])
        print(query(r) - query(l - 1))