n,x=map(int,input().split())
cnt=0
for i in range(1,n+1):
    tmp=i
    while tmp:
        if tmp%10==x:
            cnt+=1
        tmp//=10
print(cnt)