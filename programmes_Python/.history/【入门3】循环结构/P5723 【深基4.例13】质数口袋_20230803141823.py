N=1000000
L=int(input())
prime=[]
isPrime=[1 for i in range(0,N+1)]
isPrime[1]=0
for i in range(2,N+1):
    if isPrime[i]:
        prime.append(i)
    for item in prime:
        if item*i>N:
            break
        isPrime[item*i]=0
    if i%item==0:
        break
print(prime)
sum,cnt=0,0
ans=[]
for item in prime:
    if sum+item<=L:
        sum+=item
        ans.append(item)
        cnt+=1
    else:
        break
for item in ans:
    print(item)
print(cnt)
