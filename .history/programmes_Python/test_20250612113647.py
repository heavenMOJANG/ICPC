n = int(input())
a = [0] + list(map(int, input().split()))
ans = 0
vis = [0] * (n + 1)
for i in range(1, n + 1):
    if i != p[i]:
        cnt = 0
        cur = p[i]
        while vis[cur] == 0:
            vis[cur] = 1
            cur = p[cur]
            cnt += 1
        ans += max(0, cnt - 1)
print(ans)