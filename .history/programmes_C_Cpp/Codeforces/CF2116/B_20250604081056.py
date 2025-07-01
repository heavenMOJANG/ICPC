def solve():
    MOD = 998244353
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    pa, pb = 0, 0
    for i in range(n):
        if a[i] > a[pa]: pa = i
        if b[i] > b[pb]: pb = i
    x, y = [a[pa], b[i - pa]], [b[pb], a[i - pb]]
    if x < y:
        x = y
    print(pow(2, x[0], MOD) + pow(2, x[1], MOD), end = " ")
    print()
_ = int(input())
while _ > 0:
    solve()
    _ -= 1