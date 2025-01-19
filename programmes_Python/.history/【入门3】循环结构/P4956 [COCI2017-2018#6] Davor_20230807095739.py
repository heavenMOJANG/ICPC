n=int(input())
n//=52*7
k=1
while 1:
    x=n-3*k
    if 1<=x<=100:
        print("{:d}\n{:d}".format(x,k),end="")
        exit(0)
    k+=1