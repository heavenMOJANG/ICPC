a,b,c=map(int,input().split())
lst=[(a,'A'),(b,'B'),(c,'C')]
lst.sort(key=lambda x:x[0])
print(lst)