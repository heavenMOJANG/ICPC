#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Edge {
    int u, v, w, id, vis;
    bool operator < (const Edge & x) const {
        return w > x.w;
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> e(m + 1);
    priority_queue<Edge> pq;
    for (int i = 1; i <= m; ++ i) {
        cin >> e[i].u >> e[i].v;
        e[i].id = e[i].w = i;
        e[i].vis = 0;
        pq.push(e[i]);
    }
    vector<vector<int>> fa;
    fa.emplace_back(vector<int>(n + 1, 0));
    vector<int> vis(n + 1, 0);
    int maxn = 0;
    function<int(int, int)> find = [&](int id, int x) {
        return fa[id][x] == x ? x : fa[id][x] = find(id, fa[id][x]);
    };
    while (!pq.empty()) {
        auto [u, v, w, id, turn] = pq.top(); pq.pop();
        if (vis[v] > vis[u]) swap(u, v);
        int l = 0, r = vis[v];
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (find(mid, v) == find(mid, u)) l = mid;
            else r = mid - 1;
        }
        r ++;
        vis[v] = max(vis[v], r);
        vis[u] = max(vis[u], r);
        if (r + 1 > fa.size()) {
            fa.emplace_back(vector<int>(n + 1, 0));
            iota(fa[r].begin(), fa[r].end(), 0);
        }
        fa[r][find(r, v)] = find(r, u);
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}