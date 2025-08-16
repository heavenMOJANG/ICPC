#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    struct Node {
        vector<int> path;
        int u;
        bool operator < (const Node& b) const { return b.path < path; }
    }
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> g[n + 1];
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++ i) sort(g[i].begin(), g[i].end());
    vector<int> pri[n + 1], vis(n + 1, 0);

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}