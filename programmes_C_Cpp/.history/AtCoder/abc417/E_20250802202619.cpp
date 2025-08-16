#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    struct Node {
        vector<int> path;
        int id;
        bool operator < (const Node& b) const { return b.path < path; }
    };
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> g[n + 1];
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++ i) sort(g[i].begin(), g[i].end());
    vector<int> pro[n + 1], vis(n + 1, 0);
    priority_queue<Node> pq;
    pq.push({pro[x] = {x}, x});
    while (!pq.empty()) {
        Node u = pq.top(); pq.pop();
        if (vis[u.id] || u.path != pro[u.id]) continue;
        vis[u.id] = 1;
        if (u.id == y) break;
        for (int v : g[u.id]) {
            if (vis[v]) continue;
            bool ok = 0;
            for (int w : u.path) if (w == v) { ok = 1; break; }
            if (ok) continue;
            vector tmp = u.path;
            tmp.emplace_back(v);
            if (pro[v].empty() || tmp < pro[v]) pq.push({pro[v] = tmp, v});
        }
    }
    auto ans = pro[y];
    for (int i{}; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}