f=[0]*1010
f[1]=1
n=int(input())
for i in range(2,n+1,1):
    f[i]=f[i-1]
    if i%2==0:
        f[i]+=f[i//2]
print(f[n])