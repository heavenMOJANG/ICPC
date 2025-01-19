n,k=map(int,input().split())
g=[[0 for j in range(0,10)] for i in range(0,11)]
h=[1 for i in range(0,10)]
for i in range(0,k):
    u,v=map(int,input().split())
    g[u][v]=1
for k in range(0,10):
    for i in range(0,10):
        for j in range(0,10):
            g[i][j]|=g[i][k] and g[k][j]
for i in range(0,10):
    g[i][i]=0
for i in range(0,10):
    for j in range(0,10):
        if g[i][j]==1:
            h[i]+=1
ans=1
while n!=0:
    ans*=h[n%10]
    n//=10
print(ans)