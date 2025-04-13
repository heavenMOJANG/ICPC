mod = 1 * 10 ** 9 + 7
ans = 1
for i in range(10000):
    ans *= 9
    ans %= mod
print((ans - 2 + mod) % mod)