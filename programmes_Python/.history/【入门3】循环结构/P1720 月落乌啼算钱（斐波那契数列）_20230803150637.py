from math import sqrt
n=int(input())
res=((((1+sqrt(5))/2)**n)-(((1-sqrt(5))/2*))*n)/sqrt(5)
print("{:.2f}".format(res))