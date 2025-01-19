a=[0]+list(map(int,input.split()))
x=int(input())+30
sum=0
for i in range(1,11):
    if x>=a[i]:
        sum+=1
print(sum)