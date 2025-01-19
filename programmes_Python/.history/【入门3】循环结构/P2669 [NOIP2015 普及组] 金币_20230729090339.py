k=int(input())
coin,day=1,1
cnt=1
sum=0
while day<=k:
    for i in range(1,min(coin+1,day+1)):
        sum+=coin
        day+=1
    