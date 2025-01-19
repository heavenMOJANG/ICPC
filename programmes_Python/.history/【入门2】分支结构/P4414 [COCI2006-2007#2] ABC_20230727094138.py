a,b,c=map(int,input().split())
lst=[[a,'A'],[b,'B'],[c,'C']]
lst.sort(key=takeFirst)
print(lst)