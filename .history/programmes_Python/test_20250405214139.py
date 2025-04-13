class Node:
    def __init__(self, id, score, pid=0, prk=0, rk=0):
        self.id = id
        self.score = score
        self.pid = pid
        self.prk = prk
        self.rk = rk
def cmp(a, b):
    if a.score != b.score:
        return b.score - a.score
    return (a.id > b.id) - (a.id < b.id)
n = int(input())
f = []
for i in range(1, n + 1):
    k = int(input())
    v = []
    for _ in range(k):
        id, score = input().split()
        score = int(score)
        v.append(Node(id, score, pid=i))
    v.sort(key=lambda x: (-x.score, x.id))
    v[0].prk = 1
    f.append(v[0])
    for j in range(1, k):
        if v[j].score == v[j - 1].score:
            v[j].prk = v[j - 1].prk
        else:
            v[j].prk = j + 1
        f.append(v[j])
f.sort(key=lambda x: (-x.score, x.id))
f[0].rk = 1
for i in range(1, len(f)):
    if f[i].score == f[i - 1].score:
        f[i].rk = f[i - 1].rk
    else:
        f[i].rk = i + 1
print(len(f))
for node in f:
    print(f"{node.id} {node.rk} {node.pid} {node.prk}")