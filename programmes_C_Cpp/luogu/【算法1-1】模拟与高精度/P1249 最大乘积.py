n=eval(input())
lst=[]
pos=0
if n==3:
    print("1 2\n2")
else:
    k,sum=2,2
    lst.append(k)
    while 1:
        if sum+k+1<=n:
            k+=1
            sum+=k
            lst.append(k)
        else:
            break
    d=n-sum
    lst.sort(reverse=True)
    while d>0:
        for i in range(0,len(lst)):
            if d>0:
                lst[i]+=1
                d-=1
    res=1
    for i in lst:
        res*=i
    lst.sort()
    for i in range(0,len(lst)):
        print(lst[i],end=" ")
    print()
    print(res)