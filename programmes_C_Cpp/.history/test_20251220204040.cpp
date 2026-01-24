#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义边的结构体
struct Edge {
    int to;     // 目标节点 ID
    int weight; // 追加的数值 y
};

// 全局变量存储图和结果
int N;
vector<vector<Edge>> adj; // 邻接表
vector<int> ans;          // 存储最终排列 P

/**
 * 核心递归函数
 * current_nodes: 当前这一步所有代表相同序列前缀的节点集合
 */
void solve(const vector<int>& current_nodes) {
    if (current_nodes.empty()) return;

    // 收集当前所有节点的所有出边
    // 存储格式: pair<权重 y, 目标节点 id>
    vector<pair<int, int>> next_edges;

    for (int u : current_nodes) {
        for (const auto& edge : adj[u]) {
            next_edges.push_back({edge.weight, edge.to});
        }
    }

    // 如果没有子节点，直接返回
    if (next_edges.empty()) return;

    // 排序规则：
    // 1. 权重小的优先 (字典序小)
    // 2. 权重相同时，下标小的优先 (题目要求的 Tie-breaker)
    sort(next_edges.begin(), next_edges.end());

    // 按权重分组处理
    int m = next_edges.size();
    int i = 0;
    while (i < m) {
        int j = i;
        int current_w = next_edges[i].first;
        
        // 找到所有权重相同的边构成一组
        vector<int> next_group;
        while (j < m && next_edges[j].first == current_w) {
            int v = next_edges[j].second;
            // 因为 v 代表的序列是 (当前前缀 + current_w)，它是其子孙的前缀
            // 所以 v 在字典序上小于它的所有后代，立即加入结果
            ans.push_back(v);
            next_group.push_back(v);
            j++;
        }
        
        // 递归处理这一组节点
        solve(next_group);
        
        //以此类推处理下一个权重的组
        i = j;
    }
}

int main() {
    // 优化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    // 初始化邻接表，大小为 N + 1
    adj.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        // x_i < i，建立有向边 x -> i，权重 y
        adj[x].push_back({i, y});
    }

    // 从根节点 0 开始递归
    // 注意：0 号节点代表空序列，题目要求输出 1 到 N 的排列，
    // 所以 0 不加入 ans，只作为起点。
    solve({0});

    // 输出结果
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}