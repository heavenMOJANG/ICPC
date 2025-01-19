n=int(input())
a=[0]+list(map(int,input().split()))
r=[0 for i in range(1,a.size())]
for i in range(1,n+1):
    for j in range(1,i):
        if a[j]<a[i]:
            r[i]+=1
for i in range(1,n+1):
    print(r[i],end=" ")