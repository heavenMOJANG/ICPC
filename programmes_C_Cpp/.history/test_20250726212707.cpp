#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 定义 long long 以防止整数溢出
using ll = long long;

// 全局变量以便在DFS中访问
int N, K;
vector<ll> A;
vector<vector<int>> adj;
// dp[u][k][0]: u子树, k条路径, u自包含
// dp[u][k][1]: u子树, k条路径, u向上连接
vector<vector<vector<ll>>> dp;

void dfs(int u, int p) {
    // 1. 初始化当前节点 u 的 DP 表
    // 状态无效时值为-1。因为所有A_i为正，和不会是-1。
    
    // 0条路径，u自包含，价值0
    dp[u][0][0] = 0;
    // 1条路径(仅u)，u自包含，价值A[u]
    if (1 <= K) {
        dp[u][1][0] = A[u];
        // 1条路径(从u开始向上)，u向上连接，价值A[u]
        dp[u][1][1] = A[u];
    }


    // 遍历 u 的所有子节点
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }

        // 递归计算子节点 v 的 DP 表
        dfs(v, u);

        // 创建一个临时 DP 表，用于存储合并 u 和 v 之后的结果
        // prev_dp_u 存储合并前 u 的状态
        auto prev_dp_u = dp[u];
        
        // 将 u 的当前状态重置为无效，我们将从 prev_dp_u 和 dp[v] 中重新计算它
        for (int k = 0; k <= K; ++k) {
            dp[u][k][0] = -1;
            dp[u][k][1] = -1;
        }

        // 遍历 u 的旧状态 (prev_dp_u) 和 v 的状态 (dp[v])
        for (int ku = 0; ku <= K; ++ku) {
            // 如果 u 的旧状态无效，则跳过
            if (prev_dp_u[ku][0] == -1 && prev_dp_u[ku][1] == -1) continue;

            for (int kv = 0; kv <= K; ++kv) {
                // 如果 v 的状态无效，则跳过
                if (dp[v][kv][0] == -1 && dp[v][kv][1] == -1) continue;
                
                int total_k = ku + kv;

                // --- 情况 1: 不连接 u 和 v ---
                // u 和 v 的路径集保持独立。v 必须是自包含的。
                if (total_k <= K) {
                    // 1a: u 自包含 + v 自包含 -> u 保持自包含
                    if (prev_dp_u[ku][0] != -1 && dp[v][kv][0] != -1) {
                        dp[u][total_k][0] = max(dp[u][total_k][0], prev_dp_u[ku][0] + dp[v][kv][0]);
                    }
                    // 1b: u 向上连接 + v 自包含 -> u 保持向上连接
                    if (prev_dp_u[ku][1] != -1 && dp[v][kv][0] != -1) {
                        dp[u][total_k][1] = max(dp[u][total_k][1], prev_dp_u[ku][1] + dp[v][kv][0]);
                    }
                }

                // --- 情况 2: 连接 u 和 v ---
                // u 向上连接 + v 向上连接 -> 合并为一条新路径，u 变为自包含
                // 总路径数减少 1
                if (total_k > 0 && total_k - 1 <= K) {
                    if (prev_dp_u[ku][1] != -1 && dp[v][kv][1] != -1) {
                        dp[u][total_k - 1][0] = max(dp[u][total_k - 1][0], prev_dp_u[ku][1] + dp[v][kv][1]);
                    }
                }
            }
        }
    }
}

int main() {
    // 快速输入输出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    A.resize(N + 1);
    adj.resize(N + 1);
    // DP表大小为 (N+1) x (K+1) x 2，并初始化为-1
    dp.assign(N + 1, vector<vector<ll>>(K + 2, vector<ll>(2, -1)));

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    
    // 从根节点1开始DFS (父节点设为0)
    dfs(1, 0);

    // 最终答案是根节点所有自包含状态中的最大值
    ll max_sum = 0;
    for (int k = 0; k <= K; ++k) {
        if (dp[1][k][0] != -1) {
            max_sum = max(max_sum, dp[1][k][0]);
        }
    }

    cout << max_sum << endl;

    return 0;
}