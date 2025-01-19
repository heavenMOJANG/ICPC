from math import sqrt
n=int(input())
res=(((1+sqrt(5))**n/2)-(1-sqrt(5))**n/2))/sqrt(5)
print("{:.2f}".format(res))