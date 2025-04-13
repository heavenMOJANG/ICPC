MOD = 998244353
n = int(input())
ans = 0
for i in range(1, n):
  ans += i * (n - 1)
  ans %= MOD
print((ans + n) % MOD)