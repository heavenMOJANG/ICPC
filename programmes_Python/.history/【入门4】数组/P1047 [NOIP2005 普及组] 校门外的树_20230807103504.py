l,m=map(int,input().split())
a=[0]+[1 for i in range(1,n+1)]
for i in range(1,m+1):
    left,right=map(int,input().split())
    l-=right-left+1
print(l)