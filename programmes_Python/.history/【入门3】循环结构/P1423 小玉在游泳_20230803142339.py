s=float(input())
sum,step=0.0,2.0
cnt=0
while sum<=s:
    sum+=step
    step*=0.98
    cnt+=1
print(cnt)