import math
T=eval(input())
while T>0:
    a=[0]*10010
    n=eval(input())
    lst=input().split(' ')
    for i in range(1,n+1):
        a[i]=eval(lst[i-1])
    for i in range(1,n+1):
        if i==2:
            continue
        gcd=math.gcd(a[2],a[i])
        a[2]//=gcd
        a[i]//=gcd
    if a[2]==1:
        print('Yes')
    else:
        print('No')
    T-=1
