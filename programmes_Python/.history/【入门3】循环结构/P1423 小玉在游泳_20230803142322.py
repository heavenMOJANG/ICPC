s=float(input())
sum,step,cnt=0,2.0,0
while sum<=s:
    sum+=step
    step*=0.98
    cnt+=1
print(cnt)