#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1], vis(n + 1, 0);
    vector<int> dep(n + 1, 0);
    for (int i = 0, u, v; i < m; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int maxn = 0;
    function<void(int, int, int)> dfs = [&](int u, int f, int idx) {
        if (vis[u]) return;
        for (auto v : g[u]) vis [v] = 1;
        for (auto v : g[u]) {
            if (v == f) continue;
            vis[v] = 0;
            dep [v] = dep[u] + 1; maxn = max(maxn, dep[v]);
            dfs(v, u, idx);
            vis[v] = 1;
            dep [v] = 0;
        }
    };
    for (int i = 1; i <= n; ++ i) {
        fill(vis.begin(), vis.end(), 0);
        dep[i] = 0;
        dfs(i, -1, i);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}