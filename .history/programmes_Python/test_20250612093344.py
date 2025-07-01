def fac(n):
    f0, f1, f2, f3 = 0, 0, 0, 0
    while n > 0:
        x = n % 10
        if x == 3:
            f3 = 1
        if x == 2:
            if f3 == 1: f2 = 1
            if f1 == 1: f0 = 1
        if x == 0:
            if f2 == 1: f1 = 1
        n //= 10
    return 1 if f0 == 1 else 0
ans = 0
L, R = 12345678, 98765433
for x in range(L, R):
    ans += fac(x)
print(R - L - ans)