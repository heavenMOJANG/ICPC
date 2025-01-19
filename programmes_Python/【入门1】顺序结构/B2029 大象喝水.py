h,r=map(int,input().split())
h/=10
r/=10
v=3.14*(r**2)*h
a=20/v
aa=int(round(a))
print("{:d}".format(aa if aa==a else aa+1))
