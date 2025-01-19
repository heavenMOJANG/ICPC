x=int(input())
f1=(x%2==0)
f2=(4<x<=12)
print(1 if f1 and f2 else 0,1 if f1 or f2 else 0,1 if (not f1 and f2) or (f1 and not f2),)