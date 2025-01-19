k=int(input())
coin,day=1,1
sum,flag=0,1
while day<=k:
    if flag==0:
        break
    for i in range(1,coin+1):
        if day==k:
            flag=0
            break
        sum+=coin
        day+=1
        print(day)
    coin+=1
print(sum)
    