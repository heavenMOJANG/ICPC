import sys
n = int(sys.stdin.read())
cnt = 0
while n != 0:
    nn, tmp = n, 0
    while nn != 0:
        tmp += nn % 10
        nn //= 10
    n -= tmp
    cnt += 1
print(cnt)