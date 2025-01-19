f=[0]*5010
f[1]=1
f[2]=2
n=int(input())
for i in range(3,n+1,1):
    f[i]=f[i-1]+f[i-2]
print(f[n])