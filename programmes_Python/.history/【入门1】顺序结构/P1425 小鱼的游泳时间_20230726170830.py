a,b=map(int,input().split())
c,d=map(int,input().split())
t1=a*60+b
t2=c*60+d
t=t2-t1
print("{:d} {:d}".format(t//60,t%60))