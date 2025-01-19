f=[0]*1010
f[1]=1
f[2]=1
lst=input().split()
m=int(lst[0])
n=int(lst[1])
for i in range(3,n-m+2,1):
    f[i]=f[i-1]+f[i-2]
print(f[n-m+1])