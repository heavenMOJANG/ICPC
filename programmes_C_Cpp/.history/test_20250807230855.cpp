#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

// DSU (并查集) 结构体
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
    ll x, y;
    int id;
};

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    vector<Interval> intervals(n);
    ll initial_sum = 0;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        intervals[i] = {a[i], b[i], i};
        initial_sum += b[i] - a[i];
    }

    sort(intervals.begin(), intervals.end(), [](const Interval& p, const Interval& q) {
        return p.x < q.x;
    });

    // 步骤 2: 寻找连通分量
    DSU dsu(n);
    if (n > 0) {
        ll max_y_so_far = intervals[0].y;
        int current_comp_root_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (intervals[i].x <= max_y_so_far) {
                dsu.unite(intervals[current_comp_root_idx].id, intervals[i].id);
            } else {
                current_comp_root_idx = i;
            }
            max_y_so_far = max(max_y_so_far, intervals[i].y);
        }
    }
    
    // 步骤 3: 确定超级区间
    map<int, pair<ll, ll>> super_interval_map;
    for (int i = 0; i < n; ++i) {
        int root = dsu.find(i);
        if (super_interval_map.find(root) == super_interval_map.end()) {
            super_interval_map[root] = {a[i], b[i]};
        } else {
            super_interval_map[root].first = min(super_interval_map[root].first, a[i]);
            super_interval_map[root].second = max(super_interval_map[root].second, b[i]);
        }
    }

    vector<pair<ll, ll>> super_intervals;
    for (auto const& [key, val] : super_interval_map) {
        super_intervals.push_back(val);
    }
    sort(super_intervals.begin(), super_intervals.end());

    // 步骤 4: 计算收益
    int m = super_intervals.size();
    ll free_moves = n - m;
    ll gain = 0;

    if (k > free_moves) {
        ll bridges_to_build = k - free_moves;
        vector<ll> gaps;
        for (size_t i = 0; i < super_intervals.size() - 1; ++i) {
            gaps.push_back(super_intervals[i+1].first - super_intervals[i].second);
        }
        sort(gaps.begin(), gaps.end());
        
        for (size_t i = 0; i < min((ll)gaps.size(), bridges_to_build); ++i) {
            gain += gaps[i] * 2;
        }
    }

    // 步骤 5: 输出结果
    cout << initial_sum + gain << "\n";
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