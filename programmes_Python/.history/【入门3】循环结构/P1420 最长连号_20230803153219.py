n=int(input())
a=[0]+list(map(int,input().split()))
maxn=0
cnt=1
for i in range(2,n+1):
    if a[i]-a[i-1]==1:
        cnt+=1
    else:
        maxn=max(maxn,cnt)
        cnt=1
print(maxn)