n=int(input())
a=list(map(int,input().split()))
sum=0.0
for i in range(0,n):
    sum+=a[i]
sum-=max(a)+min(a)
sum/=n-2
print(sum)
