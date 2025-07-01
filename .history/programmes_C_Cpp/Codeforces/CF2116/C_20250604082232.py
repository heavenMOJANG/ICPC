from math import gcd, inf
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    d = 0
    minn = int(inf)
    for x in a:
        d = gcd(d, x)
        minn = min(minn, x)
    if minn == d:
        print(n - a.count(d))
        return
    dp = [int(inf)] * 5001
    dp[0] = 0
    for i in range(n):
        for j in range(1, 5001):
            dp[gcd(a[i], j)] = min(dp[gcd(a[i], j)], dp[j] + 1)
        dp[a[i]] = 1
    print(dp[d] + n - 2)
_ = int(input())
while _ > 0:
    solve()
    _ -= 1