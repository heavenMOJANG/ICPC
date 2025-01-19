k=int(input())
coin,day=1,1
sum=0
while day<=k:
    for i in range(1,coin+1,day+1):
        if day==k:
            break
        sum+=coin
        day+=1
        print(day)
    coin+=1
print(sum)
    