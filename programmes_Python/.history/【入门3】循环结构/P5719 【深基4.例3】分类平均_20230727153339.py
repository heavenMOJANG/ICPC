n,k=map(int,input().split())
suma,cnta,sumb,cntb=0,0,0,0
for i in range(1,n+1):
    if i%k==0:
        suma+=i;cnta+=1
    else:
        sumb+=i;cntb+=1