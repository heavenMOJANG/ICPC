class Node:
    def __init__(self):
        self.chn=0
        self.mat=0
        self.eng=0
        self.sum=0
n=int(input())
a=[Node for i in range(0,1011)]
cnt=0
for i in range(1,n+1):
    a[i].chn,a[i].mat,a[i].eng=map(int,input().split())
    a[i].sum=a[i].chn+a[i].mat+a[i].eng
for i in range(1,n):
    for j in range(i+1,n+1):
        if abs(a[i].chn-a[j].chn)<=5 and abs(a[i].mat-a[j].mat)<=5 and abs(a[i].eng-a[j].eng)<=5 and abs(a[i].sum-a[j].sum)<=10:
            cnt+=1
            print(i,j)
print(cnt)