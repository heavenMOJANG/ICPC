a,b,c=map(int,input().split())
lst=[[a,'A'],[b,'B'],[c,'C']]
lst.sort(x key=lambda x:lst[0])
print(lst)