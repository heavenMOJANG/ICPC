lst=list(map(int,input().split()))
s=input()
a,b,c=lst[0],lst[1],lst[2]
lst.sort(key=lambda x:x[0])
print(lst)