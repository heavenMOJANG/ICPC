from math import pow
def fastPow(a, x):
    res = 1
    while x > 0:
        if x & 1:
            res = res * a
        a = a * a
        x >>= 1
    return res
def check(x, n, k):
    t = fastPow(x, k)
    if abs(n - t) < pivot:
        pivot = t
        return True
    else:
        return False
def solve():
    n, k = map(int, input().split())
    if k == 1:
        print(n)
        return
    l, r = 1, 1e18
    pivot = 1e36
    while l < r:
        mid = (l + r) // 2
        if (check(mid, n, k)):
            r = mid
        else:
            l = mid + 1
    print(l)
_ = int(input())
pivot = 0
while _ > 0:
    solve()
    _ -= 1