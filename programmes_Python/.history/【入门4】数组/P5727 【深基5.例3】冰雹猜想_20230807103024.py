n=int(input())
a=[n]
while n!=1:
    if n%2==1:
        n=n*3+1
    else:
        n//=2
    a.append(n)
for item in a[::-1]:
    print(item,end=" ")