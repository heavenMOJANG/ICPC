def fastPow(a, x):
    res = 0
    while x > 0:
        if x & 1:
            res = res * a
        a = a * a
        x >>= 1
    return res
def solve():
    n, k = map(int, input().split())
    if k == 1:
        print(n)
        return
    m0 = int(n ** (1/ k))
    m1 = m0 + 1
    minn, m = abs(n - fastPow(m0, k)), m0
    if abs(n - m1 ** k) < minn:
        minn, m = abs(n - m1 ** k), m1
    print(m)
_ = int(input())
while _ > 0:
    solve()
    _ -= 1