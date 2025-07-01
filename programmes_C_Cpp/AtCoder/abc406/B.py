n, k = map(int, input().split())
a = list(map(int, input().split()))
ans, lmt = 1, 10 ** k
for x in a:
    ans = ans * x
    if ans >= lmt: ans = 1
print(ans)