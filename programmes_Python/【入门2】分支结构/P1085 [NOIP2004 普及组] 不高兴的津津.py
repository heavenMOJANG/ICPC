week=[0]
for i in range(1,8):
    x,y=map(int,input().split())
    week.append(x+y)
maxn,p=0,0
for i in range(1,8):
    if week[i]>maxn:
        maxn,p=week[i],i
if maxn<=8:
    print(0)
else:
    print(p)