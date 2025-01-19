def count_valid_intervals(N, M, L, R):
    # 初始化事件列表
    events = []
    for i in range(N):
        events.append((L[i], R[i]))
    
    # 按照 L_i 排序
    events.sort()
    
    # 统计被标记的区间对数量
    invalid_count = 0
    r = 1
    for l in range(1, M + 1):
        while r <= M and (not events or r < events[0][0]):
            r += 1
        if r <= M and events and l <= events[0][0] and events[0][1] <= r:
            invalid_count += (M - r + 1)
            events.pop(0)
    
    # 计算总数
    total_count = M * (M + 1) // 2
    
    # 返回结果
    return total_count - invalid_count
N, M = map(int, input().split())
L = [0 for i in range(N)]
R = [0 for i in range(N)]
for i in range(N):
    L[i], R[i] = map(int, input().split())
print(count_valid_intervals(N, M, L, R))