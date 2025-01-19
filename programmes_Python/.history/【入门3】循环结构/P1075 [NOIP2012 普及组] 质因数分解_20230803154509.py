from math import sqrt
n=int(input())
N=int(sqrt(n))
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