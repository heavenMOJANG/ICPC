t=eval(input())
while t>0:
    lst=input().split()
    n=eval(lst[0])
    a=eval(lst[1])
    res=1
    for i in range(1,n+1):
        res*=i
    cnt=0
    while res>0:
        if res%10==a:
            cnt+=1
        res//=10
    print(cnt)
    t-=1
