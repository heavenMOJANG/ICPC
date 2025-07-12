import sys
input = sys.stdin.readline

INF = 10**30

def solve():
    t = int(input())
    out = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))

        total_cost = 0
        # 对每一位 k 单独做 DP
        for k in range(29):
            # 提取第 k 位
            ak = [(a_i >> k) & 1 for a_i in a]
            bk = [(b_i >> k) & 1 for b_i in b]

            # dp[i][0/1]
            dp0, dp1 = INF, INF
            # i = 1 的初始
            if bk[0] == 0:
                dp0 = 0
                dp1 = 1 << k
            else:
                dp0 = INF
                dp1 = 0

            # 逐步转移
            for i in range(1, n):
                ndp0, ndp1 = INF, INF
                for prev, dp_prev in ((0, dp0), (1, dp1)):
                    if dp_prev >= INF: 
                        continue
                    for cur in (0, 1):
                        # 强制条件
                        if ak[i-1] == 1:
                            if not (prev == 1 and cur == 1):
                                continue
                        else:
                            if prev == 1 and cur == 1:
                                continue
                        cost = dp_prev
                        # 如果原来是0，现在选1，要付 2^k
                        if cur == 1 and bk[i] == 0:
                            cost += (1 << k)
                        # 更新
                        if cur == 0:
                            ndp0 = min(ndp0, cost)
                        else:
                            ndp1 = min(ndp1, cost)
                dp0, dp1 = ndp0, ndp1

            best = min(dp0, dp1)
            if best >= INF:
                total_cost = -1
                break
            total_cost += best

        out.append(str(total_cost))

    print("\n".join(out))


if __name__ == "__main__":
    solve()
