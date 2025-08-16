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

// 用于对vector进行哈希，以快速比较邻接表
const long long P1 = 31, M1 = 1e9 + 7;
const long long P2 = 37, M2 = 1e9 + 9;

pair<long long, long long> get_hash(const vector<int>& vec) {
    long long hash1 = 0, hash2 = 0;
    long long p_pow1 = 1, p_pow2 = 1;
    for (int x : vec) {
        // 使用两个不同的质数和模数来减少哈希碰撞的概率
        hash1 = (hash1 + (long long)x * p_pow1) % M1;
        hash2 = (hash2 + (long long)x * p_pow2) % M2;
        p_pow1 = (p_pow1 * P1) % M1;
        p_pow2 = (p_pow2 * P2) % M2;
    }
    return {hash1, hash2};
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

    q.push(1); // 从节点1开始染色
    color[1] = 0;
    
    int head_ptr = 0;
    vector<int> component_nodes;
    component_nodes.push_back(1);
    
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
    
    // 步骤2: 对邻接表排序并分组等价节点
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // 使用哈希值作为map的键来对节点进行分组
    map<pair<long long, long long>, vector<int>> groups;
    vector<pair<long long, long long>> node_hashes(n + 1);
    for (int i = 1; i <= n; ++i) {
        node_hashes[i] = get_hash(adj[i]);
        groups[node_hashes[i]].push_back(i);
    }

    // 步骤3: 检查元图结构 (度必须 <= 2)
    for (auto const& [hash_val, nodes] : groups) {
        int u = nodes[0]; // 从组中取一个样本节点
        set<pair<long long, long long>> neighbor_group_hashes;
        // 统计其邻居属于多少个不同的组
        for (int v : adj[u]) {
            neighbor_group_hashes.insert(node_hashes[v]);
        }
        if (neighbor_group_hashes.size() > 2) {
            cout << 0 << endl; // 度大于2，无法形成无交叉排列
            return;
        }
    }

    // 步骤4: 计算总方案数
    
    // 计算等价节点组内部的排列数
    long long perm_ways = 1;
    for (auto const& [hash_val, nodes] : groups) {
        perm_ways = (perm_ways * fact[nodes.size()]) % MOD;
    }

    // 根据元图的结构（链的长度）计算最终答案
    long long ans;
    if (groups.size() > 2) { 
        // 元图是长度大于等于2的链，有4种基本结构
        // (南北岸交换 * 链条顺序颠倒 = 2 * 2 = 4)
        ans = (4 * perm_ways) % MOD;
    } else { 
        // 元图只有两个节点，只有2种基本结构
        // (南北岸交换 = 2)
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