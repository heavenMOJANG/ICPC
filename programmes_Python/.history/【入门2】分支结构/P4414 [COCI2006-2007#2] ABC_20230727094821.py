lst=list(map(int,input().split()))
s=input()
lst.sort()
a,b,c=lst[0],lst[1],lst[2]
dic={'A':a,'B':b,'C':c}
for i in range(0,3):
    print(dic[s[i]],end=' ')