n=int(input())
cnt=1
for i in range(n,0,-1):
    for j in range(1,i+1):
        print("{:0>2d}".format(cnt),end="")
        cnt+=1
    print()