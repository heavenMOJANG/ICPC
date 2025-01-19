from math import log
def solve():
    n, k = map(int, input().split())
    if k == 1:
        print(n)
        return
    x0 = log(n, k)
    m0 = int(x0)
    ml = max(0, m0 - 1)
    mr = m0 + 1
    minn, m = abs(n - ml ** k), ml
    if abs(n - m0 ** k) < minn:
        minn, m = abs(n - m0 ** k), m0
    if abs(n - mr ** k) < minn:
        minn, m = abs(n - mr ** k), mr
    print(m)
_ = int(input())
while _ > 0:
    solve()
    _ -= 1