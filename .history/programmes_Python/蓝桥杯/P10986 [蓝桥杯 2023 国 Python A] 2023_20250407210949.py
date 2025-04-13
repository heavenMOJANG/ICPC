import sys
n, m = map(int, sys.stdin.read().split())
mod = 998244353
N = int(5e5 + 10)
fac = [1] * N
for i in range(1, N):
    fac[i] = fac[i - 1] * i % mod
inv = [1] * N
inv[N - 1] = pow(fac[N - 1], mod - 2, mod)
for i in range(N - 2, -1, -1):
    inv[i] = inv[i + 1] * (i + 1) % mod
def C(n, m):
    return fac[n] * inv[n - m] % mod * inv[m] % mod if n >= m else 0
maxn = n // 4
g = [0] * (maxn + 1)
for k in range(m, maxn + 1):
    p = n - 4 * k
    if p < 0:
        continue
    c = C(k + p, k)
    res = pow(10, p, mod)
    g[k] = c * res % mod
ans = 0
for i in range(maxn, m - 1, -1):
    c = C(i, m)
    res = c * g[i] % mod
    if (i - m) % 2 == 1:
        ans = (ans - res) % mod
    else:
        ans = (ans + res) % mod
sys.stdout.write(str(ans) + '\n')