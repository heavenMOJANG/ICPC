def fac(n):
    f0, f2, f3 = 1, 1, 1
    while n > 0:

ans = 0
for x in range(12345678, 98765433):
    s, t = str(x), "2023"
    if kmp(t, s) == True:
        continue
    else:
        ans += 1
print(ans)