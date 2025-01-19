x,n=map(int,input().split())
d=n//7
a=n%7
sum=d*250*5
for i in range(1,a+1):
    if x+i-1!=6 or x+i-1!=7:
        sum+=250
print(sum)