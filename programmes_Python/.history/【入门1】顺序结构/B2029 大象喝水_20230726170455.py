h,r=map(int,input().split())
h/=10
r/=10
v=3.14*(r**2)*h
print("{:d}".format(20//v if 20%v==0 else 20//v+1))
