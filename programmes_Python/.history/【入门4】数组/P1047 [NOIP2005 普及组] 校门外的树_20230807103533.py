l,m=map(int,input().split())
a=[0]+[1 for i in range(1,l+1)]
cnt
for i in range(1,m+1):
    left,right=map(int,input().split())
    for j in range(left,right+1):
        a[j]=0
