lst=list(map(int,input().split()))
lst.sort()
a,b,c=lst[0],lst[1],lst[2]
if a+b>c:
    cosc=(a**2+b**2-c**2)/(2*a*b)
    if cosc==0:
        print("Right triangle")
    elif cosc>0:
        print("Acute triangle")
    else:
        print("Obtuse triangle")
    if a==b or b==c:
        print("Isosceles triangle")
    if a==b==c:
        print("Equilateral triangle")
    
else:
    print("Not triangle")