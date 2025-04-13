def to4(x):
    res = 0
    while x >= 4:
        res += x % 4
        x //= 4
    return res + x
def to2(x):
    res = 0
    while x >= 2:
        res += x % 2
        x //= 2
    return res + x
for i in range(1, 2025):
    if to2(i) == to4(i):
        print(i)
