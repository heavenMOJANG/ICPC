L=int(input())
prime=[0]
vis=[1 for i in range(0,1e6+1)]
def euler():
    vis[1]=0
    for i in range(2,1e6+1):
        if vis[i]:
            prime.append(i)
        j=1

