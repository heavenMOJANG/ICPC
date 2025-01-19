a,b,c=map(int,input().split()).sort()
if a+b>c:
    cosc=(a**2+b**2-c**2)/(2*a*b)
    if cosc==0:
        print("Right triangle")
    elif cosc>0:
        print("Acute triangle")
    else:
        print("Obtuse triangle")
    if a==b==c:
        print("Equilateral triangle")
    elif (a==b and b!=c) or (b==c and a!=b):
        print("Isosceles triangle")
else:
    print("Not triangle")