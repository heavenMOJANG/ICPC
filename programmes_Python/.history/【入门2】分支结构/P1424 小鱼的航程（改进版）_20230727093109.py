x,n=map(int,input().split())
d=n//7
a=n%7
sum=d*250*5
if x==7:
    x=0
for i in range(1,a+1):
    if (x+i-1)%7!=0 and (x+i-1)%7!=6:
        sum+=250
print(sum)