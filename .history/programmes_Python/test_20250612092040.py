def fac(n):
    f0, f2, f3 = 0, 0, 0
    while n > 0:
        x = n % 10
        if x == 3:
            f3 = 1
        if x == 2:
            if f3 == 1: f2 += 1
        if x == 0:
            if f2 > 0: f0 += 1
        n //= 10
    if f0 >= 1 and f2 >= 2:
        return 1
    else:
        return 0
ans = 0
for x in range(12345678, 98765433):
    ans += fac(x)
print(ans)