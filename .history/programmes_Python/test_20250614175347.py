import heapq
pq = []
for i in range(10, 0, -1):
    heapq.heappush(pq, i)
print(*pq)