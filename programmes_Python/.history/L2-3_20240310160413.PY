n = int(input())
a = [1 for i in range(0, n + 1)]
G = {}
cnt = 0
e = [0 for i in range(200010)]
nxt = [0 for i in range(200010)]
head = [-1 for i in range(200010)]
def add(u,v):
    global cnt
    e[cnt] = v
    ne1[cnt] = h1[u]#存u这一个节点的前驱顶点的下标
    h1[u] = cnt#h[u]指向v所在下标，v为边的终点，可以理解为是从u这个节点向后垂下一条链，链上是他链接的边，但是遍历时是反向的，故顺序没变，顺序是边输进来的顺序
    cnt+=1#最终cnt必然等于边数+1
depth = [0 for i in range(0, n + 1)]
def dfs(x):
    for i in G[x]:
        depth[i] = depth[x] + 1
        dfs(i)
    return
for i in range(1, n + 1):
    G[i] = []
for i in range(1,n + 1):
    d = list(map(int, input().split()))
    k = d[0]
    for j in range(1, k + 1):
        a[d[j]] = 0
        G[i].append(d[j])
root = 0
for i in range(1, n + 1):
    if a[i]:
        root = i
depth[root] = 1
dfs(root)
maxn, idx = 0, 0
for i in range(1, n + 1):
    if depth[i] > maxn:
        maxn = depth[i]
        idx = i
print(idx)