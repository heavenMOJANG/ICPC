#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<array<int, 3>> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v, p, q; cin >> u >> v >> p >> q;
        g[u].push_back({v, p, q});
        g[v].push_back({u, q, p});
    }
    vector<int> vis(n + 1, 0);
    int s, t; cin >> s >> t;
    vector<int> path, tmp;
    function<void(int, int)> dfs0 = [&](int u, int fa) {
        if (u == t) {
            path = tmp;
            for (auto x : path) vis[x] = 1;
            return;
        }
        for (auto [v, p, q] : g[u]) {
            if (v == fa) continue;
            tmp.emplace_back(v);
            dfs0(v, u);
            tmp.pop_back();
        }
    };
    tmp.emplace_back(s);
    dfs0(s, 0);
    int ans{};
    for (int i{}; i < path.size() - 1; ++ i) {
        int u = path[i], v = path[i + 1];
        for (auto [to, p, q] : g[u])
            if (to == v) { ans += p; break;}
    }
    for (auto u : path) {
        dfs1(u);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}