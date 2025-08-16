#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

// DSU 结构体
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_j] = root_i;
        }
    }
};

struct Interval {
    long long x, y;
    int id;
};

struct Gap {
    long long dist;
    int u, v; // 原始区间的ID
    bool operator>(const Gap& other) const {
        return dist > other.dist;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    vector<Interval> intervals(n);
    long long initial_sum = 0;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) {
        intervals[i].x = min(a[i], b[i]);
        intervals[i].y = max(a[i], b[i]);
        intervals[i].id = i;
        initial_sum += intervals[i].y - intervals[i].x;
    }

    sort(intervals.begin(), intervals.end(), [](const Interval& p, const Interval& q) {
        if (p.x != q.x) return p.x < q.x;
        return p.y < q.y;
    });

    DSU dsu(n);
    vector<long long> min_x(n), max_y(n);
    for(int i=0; i<n; ++i) {
        min_x[i] = intervals[i].x;
        max_y[i] = intervals[i].y;
    }

    // 使用 set 维护组件顺序，方便查找邻居
    set<int> active_components;
    for (int i = 0; i < n; ++i) {
        active_components.insert(i);
    }

    priority_queue<Gap, vector<Gap>, greater<Gap>> pq;
    for (int i = 0; i < n - 1; ++i) {
        long long dist = max(0LL, intervals[i+1].x - intervals[i].y);
        pq.push({dist, i, i+1});
    }

    long long gain = 0;
    int merges_done = 0;
    while (!pq.empty() && merges_done < k) {
        Gap current_gap = pq.top();
        pq.pop();

        int u = current_gap.u;
        int v = current_gap.v;

        int root_u = dsu.find(u);
        int root_v = dsu.find(v);

        if (root_u == root_v) {
            continue;
        }

        merges_done++;
        gain += current_gap.dist * 2;
        
        // 从 active_components 中移除旧的组件代表
        active_components.erase(root_u);
        active_components.erase(root_v);

        dsu.unite(root_u, root_v);
        int new_root = dsu.find(root_u);

        // 更新新组件的边界
        long long new_min_x = min(min_x[root_u], min_x[root_v]);
        long long new_max_y = max(max_y[root_u], max_y[root_v]);
        min_x[new_root] = new_min_x;
        max_y[new_root] = new_max_y;

        // 查找新组件的邻居并添加新的 gap 到 pq
        auto it = active_components.lower_bound(new_root);

        if (it != active_components.end()) {
            int right_neighbor_root = *it;
            long long dist = max(0LL, min_x[right_neighbor_root] - new_max_y);
            pq.push({dist, new_root, right_neighbor_root});
        }
        if (it != active_components.begin()) {
            int left_neighbor_root = *prev(it);
            long long dist = max(0LL, new_min_x - max_y[left_neighbor_root]);
            pq.push({dist, left_neighbor_root, new_root});
        }

        active_components.insert(new_root);
    }
    
    // 如果 k 大于等于 n-1，阿里可以连接所有组件
    if (k >= n - 1) {
        vector<long long> all_nums;
        for(int i=0; i<n; ++i) {
            all_nums.push_back(a[i]);
            all_nums.push_back(b[i]);
        }
        sort(all_nums.begin(), all_nums.end());
        long long max_sum = 0;
        for(int i=0; i<n; ++i) {
            max_sum -= all_nums[i];
            max_sum += all_nums[2*n-1-i];
        }
        cout << max_sum << "\n";
    } else {
        cout << initial_sum + gain << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}