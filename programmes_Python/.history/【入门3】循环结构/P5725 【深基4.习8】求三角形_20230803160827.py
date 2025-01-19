n=int(input())
idx=1
for i in range(1,n+1):
    for j in range(1,n+1):
        print("{:0>2d}".format(idx),end="")
        idx+=1
    print()
print()
cnt=n-1
idx=1
for i in range(1,n+1):
    for j in range(1,cnt+1):
        print("  ",end="")
    for j in range(cnt+1,n+1):
        print("{:0>2d}".format(idx),end="")
        idx+=1
    print()
    cnt-=1
