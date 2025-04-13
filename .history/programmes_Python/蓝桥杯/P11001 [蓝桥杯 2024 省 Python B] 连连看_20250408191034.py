n, m = map(int, input().split())
a, g = [], [[] for i in range(1001)] 
for i in range(n):
    a.append(list(map(int, input().split())))