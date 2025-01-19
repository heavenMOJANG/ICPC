pocket=0
account=0
for i in range(1,13):
    cost=int(input())
    if pocket+300<cost:
        print("-{:d}".format(i))
        exit(0)
    else:
        pocket=pocket+300-cost
        t=pocket//100
        pocket-=t*100
        account+=t*100
print(int(account*1.2)+pocket)