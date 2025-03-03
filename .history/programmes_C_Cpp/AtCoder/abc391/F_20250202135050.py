from heapq import heappop, heappush
n, k = map(int, input().split())
a = sorted(list(map(int, input().split())), reverse = True)
b = sorted(list(map(int, input().split())), reverse = True)
c = sorted(list(map(int, input().split())), reverse = True)
s = set()
pq = []
def add(i, j, k):
    if i < n and j < n and k < n and (i, j, k) not in s:
        s.add((i, j, k))
        heappush(pq, -(a[i] * b[j] + b[j] * c[k] + c[k] * a[i]), i, j, k)
add(0, 0, 0)
for x in range(k):
    val, i, j, k = heappop(pq)
    if x == k - 1:
        print(- val)
    add(i + 1, j, k)
    add(i, j + 1, k)
    add(i, j, k + 1)