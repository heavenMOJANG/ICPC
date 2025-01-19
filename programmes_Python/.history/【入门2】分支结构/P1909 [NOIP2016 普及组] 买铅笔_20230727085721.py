n=int(input())
price=[]
for i in range(1,4):
    a,b=map(input().split())
    d=n//a if n%a==0 else n//a+1
    price.append(b*d)
price.sort()
print(price[0])