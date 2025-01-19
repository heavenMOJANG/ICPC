lst=list(map(int,input().split()))
s=input()
list.sort()
a,b,c=lst[0],lst[1],lst[2]
dic={'A':a,'B':b,'C':c}
for it in s:
    print(dic[it],end=' ')