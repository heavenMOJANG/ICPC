N = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
p, flag = -1, True
cnt = 0
while p < N:
    if flag:
        for i in range(p + 1, N):
            if '0' in str(s[i]) or '2' in str(s[i]) or '4' in str(s[i]):
                p = i
                cnt += 1
                break
    else:
        for i in range(p + 1, N):
            if '0' in str(t[i]) or '2' in str(t[i]) or '4' in str(t[i]):
                p = i
                cnt += 1
                break
print(cnt)