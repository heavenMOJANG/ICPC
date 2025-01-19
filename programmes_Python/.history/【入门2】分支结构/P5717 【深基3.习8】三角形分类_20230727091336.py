a,b,c=map(int,input().split()).sort()
if a+b>c:
    cosc=(a**2+b**2-c**2)/(2*a*b)
else:
    print("Not triangle")