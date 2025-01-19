n=int(input())
n//=52*7
k=1
while 1:
    if 1<=(n-3*k)<=100:
        print("{:d}\n{:d}".format(n-3*k,k),end="")
        exit(0)
    k+=1