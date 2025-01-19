m,t,s=map(int,input().split())
if t==0:
    print("0")
else:
    d=s//t if s%t==0 else s//t+1
    print(m-d if m>=d else 0)