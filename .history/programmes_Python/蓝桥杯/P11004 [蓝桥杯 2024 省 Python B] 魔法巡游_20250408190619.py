N = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
p, flag = 0, True
cnt = 0
while p < N:
    if flag:
        if '0' in str(s[p]) or '2' in str(s[p]) or '4' in str(s[p]):
            cnt += 1
            flag = False
            continue
        p += 1
    else:
        if '0' in str(t[p]) or '2' in str(t[p]) or '4' in str(t[p]):
            cnt += 1
            flag = True
            continue
        p += 1
print(cnt)