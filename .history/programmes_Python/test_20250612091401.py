cnt = 0
def prefix_function(s):
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i - 1]
        while j > 0 and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi
def kmp(t, s):
    cur = s + "#" + t
    sz1, sz2 = len(t), len(s)
    lps = prefix_function(cur)
    for i in range(sz2 + 1, sz1 + sz2 + 1):
        if lps[i] == sz2:
            return True
    return False
ans = 0
for x in range(12345678, 98765433):
    s, t = str(x), "2023"
    if kmp(t, s) == True:
        continue
    else:
        ans += 1
print(ans)