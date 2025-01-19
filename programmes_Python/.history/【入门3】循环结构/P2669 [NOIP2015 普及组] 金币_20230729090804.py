k=int(input())
coin,day=1,1
sum,flag=0,1
while day<=k:
    for i in range(1,coin+1):
        day+=1
        if day>k:
            break
        else:
            sum+=coin
        print(i)
    coin+=1
print(sum)
    