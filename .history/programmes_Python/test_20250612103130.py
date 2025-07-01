class DSU:
    def __init__(self):
        self.n = 0
        self.top = 0
        self.fa = [i for i in range(300001)]
        self.sz = [0] * 300000
        self.st = [0] * 300000
    def ins(self):
        self.n += 1
        self.fa[self.n] = self.n
        self.sz[self.n] = 1
    def findSet(self, x):
        if self.fa[x] == x: return x
        else: self.fa[x] = self.findSet(self.fa[x])
