#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

// 定义模数
const int MOD = 1e9 + 7;
// 定义节点和边的最大数量
const int MAXN_SUM = 200005;

// 预计算阶乘
long long fact[MAXN_SUM];

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN_SUM; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 步骤1: 检查二分性 (题目保证图是连通的)
    vector<int> color(n + 1, -1);
    queue<int> q;
    bool is_bipartite = true;

    // 题目保证图是连通的，所以从任意一个节点开始即可
    q.push(1);
    color[1] = 0;
    
    // 使用BFS进行染色
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                // 发现冲突，不是二分图
                is_bipartite = false;
            }
        }
    }

    if (!is_bipartite) {
        cout << 0 << endl;
        return;
    }
    
    // 步骤2: 对邻接表排序并使用 vector 作为键来分组
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // 使用 vector<int> 作为 map 的键来对节点进行分组
    map<vector<int>, vector<int>> groups;
    for (int i = 1; i <= n; ++i) {
        groups[adj[i]].push_back(i);
    }

    // 步骤3: 检查元图结构 (度必须 <= 2)
    // 遍历每一个分组（元节点）
    for (auto const& [adj_list_key, nodes_in_group] : groups) {
        if (nodes_in_group.empty()) continue;

        int u = nodes_in_group[0]; // 从组中取一个样本节点
        
        // 使用一个 set 来存储其邻居所属的不同分组的键(即邻接表)
        // set<vector<int>> 会自动处理重复的邻接表
        set<vector<int>> neighbor_groups;
        
        // 统计其邻居属于多少个不同的组
        for (int v : adj[u]) {
            neighbor_groups.insert(adj[v]);
        }
        
        // 如果邻居来自超过两个不同的分组，则元图在该节点处产生分支
        if (neighbor_groups.size() > 2) {
            cout << 0 << endl; // 度大于2，无法形成无交叉排列
            return;
        }
    }

    // 步骤4: 计算总方案数
    
    // 计算等价节点组内部的排列数
    long long perm_ways = 1;
    for (auto const& [adj_list_key, nodes_in_group] : groups) {
        perm_ways = (perm_ways * fact[nodes_in_group.size()]) % MOD;
    }

    // 根据元图的结构（链的长度）计算最终答案
    long long ans;
    if (groups.size() > 2) { 
        // 元图是长度大于2的链，有4种基本结构
        // (南北岸交换 * 链条顺序颠倒 = 2 * 2 = 4)
        ans = (4 * perm_ways) % MOD;
    } else { 
        // 元图只有1个或2个节点，只有2种基本结构
        // (南北岸交换 = 2)
        // 例如，一个完整的二分图会产生两个元节点
        ans = (2 * perm_ways) % MOD;
    }

    cout << ans << endl;
}

int main() {
    // 优化C++的I/O性能
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials(); // 预计算阶乘

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}