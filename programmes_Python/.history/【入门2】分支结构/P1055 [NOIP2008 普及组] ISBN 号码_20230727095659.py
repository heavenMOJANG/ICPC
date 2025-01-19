isbn=input()
sum=0
cnt=0
for i in range(0,13):
    if isbn[i]=='-':
        continue
    cnt+=1
    if cnt<10:
        sum+=eval(isbn[i])*cnt
sum%=11
if sum==10:
    if isbn[12]=='X':
        print("Right")
    else:
        print(isbn[0:12],'X',sep='')
else:
    if isbn[12]=='X' or eval(isbn[12])!=sum:
        print(isbn[0:12],sum,sep='')
    else:
        print("Right")
