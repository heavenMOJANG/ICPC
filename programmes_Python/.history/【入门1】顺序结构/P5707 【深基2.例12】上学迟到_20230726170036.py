s,v=map(int,input().split())
m=s//v if s%v==0 else s//v+1
m+=10
t=8*60+1440
t-=m
t%=1440
print("{:2d}:{:2d}".format(t//60,t%60))