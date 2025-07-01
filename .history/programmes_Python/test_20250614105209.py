N = int(1e5 + 10)
val = [0] * (4 * N)
tag = [0] * (4 * N)
n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
def pushUp(p):
    val[p] = val[p << 1] + val[p << 1 | 1]
def build(p, pl, pr):
    if pl == pr:
        val[p] = a[pl]
        return
    mid = (pl + pr) // 2
    build(p << 1, pl, mid)
    build(p << 1 | 1, mid + 1, pr)
    pushUp(p)
def addTag(p, pl, pr, d):
    tag[p] += d
    val[p] += d * (pr - pl + 1)
def pushDown(p, pl, pr):
    if tag[p] != 0:
        mid = (pl + pr) // 2
        addTag(p << 1, pl, mid, tag[p])
        addTag(p << 1 | 1, mid + 1, pr, tag[p])
        tag[p] = 0
def update(L, R, p, pl, pr, d):
    if L<= pl and pr <= R:
        addTag(p, pl, pr, d)
        return
    pushDown(p, pl, pr)
    mid = (pl + pr) // 2
    if L <= mid: update(L, R, p << 1, pl, mid, d)
    if R > mid: update(L, R, p << 1 | 1, mid + 1, pr, d)
    pushUp(p)
def query(L, R, p, pl, pr):
    if L <= pl and pr <= R:
        return val[p]
    pushDown(p, pl, pr)
    mid, res = (pl + pr) // 2, 0
    if L <= mid: res += query(L, R, p << 1, pl, mid)
    if R > mid: res += query(L, R, p << 1 | 1, mid + 1, pr)
    return res
build(1, 1, n)
for testcase in range(m):
    data = list(map(int, input().split()))
    if data[0] == 1:
        l, r, d = map(int, data[1:4])
        update(l, r, 1, 1, n, d)
    if data[0] == 2:
        l, r = map(int, data[1:3])
        print(query(l, r, 1, 1, n))