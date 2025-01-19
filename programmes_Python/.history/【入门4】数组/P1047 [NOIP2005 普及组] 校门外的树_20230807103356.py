l,m=map(int,input().split())
for i in range(1,m+1):
    l,r=map(int,input().split())
    l-=r-l+1
print(l)