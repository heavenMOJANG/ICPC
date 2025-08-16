#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;

// 线段结构体，方便管理
struct Segment {
    int u, v, id;
};

// 为此题定制的并查集，记录每个连通分量的坐标范围
struct DSU {
    vector<int> parent;
    vector<int> min_val;
    vector<int> max_val;

    // 构造函数，n为最大坐标值
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        min_val.resize(n + 1);
        iota(min_val.begin(), min_val.end(), 0);
        max_val.resize(n + 1);
        iota(max_val.begin(), max_val.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // 合并两个集合，并更新范围
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // 简单的合并规则，例如让小编号的节点做父节点
            if (root_i > root_j) swap(root_i, root_j);
            parent[root_j] = root_i;
            min_val[root_i] = min(min_val[root_i], min_val[root_j]);
            max_val[root_i] = max(max_val[root_i], max_val[root_j]);
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Segment> all_segments(n);
    int max_coord = 0;
    for (int i = 0; i < n; ++i) {
        cin >> all_segments[i].u >> all_segments[i].v;
        all_segments[i].id = i + 1;
        max_coord = max({max_coord, all_segments[i].u, all_segments[i].v});
    }

    // 全局最优解，初始为空集，得分为0
    int max_score = 0;
    vector<int> optimal_indices;

    // 1. 外层循环：枚举所有可能的左端点作为基准
    for (int i = 0; i < n; ++i) {
        int L = all_segments[i].u;
        
        // 2. 筛选出所有左端点 >= L 的候选线段
        vector<Segment> candidates;
        for (const auto& seg : all_segments) {
            if (seg.u >= L) {
                candidates.push_back(seg);
            }
        }

        // 3. 贪心策略：按右端点升序排序
        sort(candidates.begin(), candidates.end(), [](const Segment& a, const Segment& b) {
            return a.v < b.v;
        });

        // 4. 为当前L构建最优森林
        DSU dsu(max_coord + 1);
        int current_score = 0;
        vector<int> current_indices;

        for (const auto& cand : candidates) {
            int root_u = dsu.find(cand.u);
            int root_v = dsu.find(cand.v);

            if (root_u != root_v) {
                // 计算得分变化
                // 减去合并前两个连通分量的长度
                current_score -= (dsu.max_val[root_u] - dsu.min_val[root_u]);
                current_score -= (dsu.max_val[root_v] - dsu.min_val[root_v]);

                dsu.unite(cand.u, cand.v);
                int new_root = dsu.find(cand.u);

                // 加上合并后新连通分量的长度
                current_score += (dsu.max_val[new_root] - dsu.min_val[new_root]);
                
                current_indices.push_back(cand.id);

                // 如果找到了更优的解，则更新
                if (current_score > max_score) {
                    max_score = current_score;
                    optimal_indices = current_indices;
                }
            }
        }
    }

    cout << optimal_indices.size() << "\n";
    for (int i = 0; i < optimal_indices.size(); ++i) {
        cout << optimal_indices[i] << " \n"[i == optimal_indices.size() - 1];
    }
    return;
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}