from math import abs
class Node:
    def __init__(self):
        self.chn=0
        self.mat=0
        self.eng=0
        self.sum=0
n=int(input())
a=[Node for i in range(0,1011)]
for i in range(1,n+1):
    a[i].chn,a[i].mat,a[i].eng=map(int,input().split())
    a[i].sum=a[i].chn+a[i].mat+a[i].eng
for i in range(2,n+1):
    for j in range(1,i):
