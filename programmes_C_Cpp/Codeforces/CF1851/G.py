import collections
import math
class UnionFind:
    def __init__(self,n:int):
        self.parent=[x for x in range(n)]
        self.size=[1 for _ in range(n)]
        self.n=n
        self.setCount=n
    def Find(self,x:int)->int:
        if self.parent[x]!=x:
            self.parent[x]=self.Find(self.parent[x])
        return self.parent[x]
    def Union(self,x:int,y:int)->bool:
        root_x=self.Find(x)
        root_y=self.Find(y)
        if root_x==root_y:
            return False
        if self.size[root_x]>self.size[root_y]:
            root_x,root_y=root_y,root_x
        self.parent[root_x]=root_y
        self.size[root_y]+=self.size[root_x]
        self.setCount-=1
        return True
    def connected(self,x:int,y:int)->bool:
        return self.Find(x)==self.Find(y)
    def members(self,x):
        root=self.Find(x)
        return [i for i in range(self.n) if self.Find(i)==root]
    def roots(self):
        return [i for i, x in enumerate(self.parent) if i == x]
    def group_count(self):
        return len(self.roots())
    def all_group_members(self):
        mp=collections.defaultdict(list)
        for member in range(self.n):
            mp[self.Find(member)].append(member)
        return mp
def solve(testcase):
    n,m=map(int,input().split())
    adj=collections.defaultdict(list)
    uf=UnionFind(n+1)
    H=[0]+list(map(int,input().split()))
    for _ in range(m):
        u,v=map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)
    points=[i for i in range(1,n+1)]
    points.sort(key=lambda x:H[x])
    cur=0
    q=int(input())
    queries=[list(map(int,input().split())) for _ in range(q)]
    idxs=[i for i in range(q)]
    idxs.sort(key=lambda x:H[queries[x][0]]+queries[x][2])
    res=[None for _ in range(q)]
    for idx in idxs:
        a,b,e=queries[idx]
        while cur<n and H[points[cur]]<=H[a]+e:
            for o in adj[points[cur]]:
                if H[o]<=H[a]+e:
                    uf.Union(points[cur],o)
            cur+=1 
        res[idx]=('YES' if uf.connected(a,b) else 'NO')
    for r in res:
        print(r)
for testcase in range(int(input())):
    solve(testcase)
    print()