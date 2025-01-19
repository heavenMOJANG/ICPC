N=1e6
L=int(input())
prime=[]
isPrime=[1 for i in range(0,N+1)]
isPrime[1]=0
for i in range(2,1e6+1):
    if isPrime[i]:
        prime.append(i)
    for item in prime:
        if item*i>N:
            break
        isPrime[item*i]=0
    if i%item==0:
        break
sum,cnt=0,0
for item in prime:

