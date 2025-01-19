import math
lst=list(map(int,input().split()))
lst.sort()
a,b,c=lst[0],lst[1],lst[2]
g=math.gcd(a,c)
a//=g
c//=g
print("{:d}/{:d}".format(a,c))