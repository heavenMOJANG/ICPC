from math import log10
a=[0]+[i for i in range(1,11)]
def solve():
    n=int(input())
    sum=0
    l=int(log10(n))+1
    for i in range(1,l):
        sum+=9*(10**(i-1))*a[i]
    sum+=(n-(10**a[l-1])+1)*a[l]
    print(sum)
if __name__ == '__main__':
    T=int(input())
    while T:
        solve()
        T-=1