n=int(input())
f=0
res=0
if n<0:
    f=1
    n=-n
while n:
    x=n%10
    res=res*10+x
    n//=10
if f:
    res*=-1
print(res)