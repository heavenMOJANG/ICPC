from datetime import datetime, timedelta
st = datetime(1970, 1, 1, 0, 0, 0)
for i in range(int(input())):
    aa, bb, x = input().split()
    y, m, d = map(int, aa.split('-'))
    h, mi, s = map(int, bb.split(':'))
    cur = datetime(y, m, d, h, mi, 0)
    diff = cur - st
    tot = int(diff.total_seconds()) // 60 % int(x)
    print(str(cur - timedelta(minutes = tot)))