from datetime import datetime, timedelta
s = datetime(1970, 1, 1, 0, 0, 0)
for i in range(int(input())):
    aa, bb, mm = input().split()
    y, m, d = map(int, aa.split('-'))
    h, mi, s = map(int, bb.split(':'))
    cur = datetime(y, m, d, h, mi, 0)
    diff = cur - s
    tot = int(diff.total_seconds()) // 60 % int(mm)
    print(str(cur - timedelta(minutes=tot)))