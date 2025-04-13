lim = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
mon, day, week, ans = 1, 1, 7, 0
for i in range(1, 366):
    if '1' in str(mon) or '1' in str(day) or '1' in str(week):
        ans += 5
    else:
        ans += 1
    week += 1
    if week == 8:
        week = 1
    day += 1
    if day > lim[mon]:
        day = 1
        mon += 1
print(ans)