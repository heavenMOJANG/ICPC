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
    vector<int> dep(n + 1, 1), up(n + 1, 0), down(n + 1, 0);
    vector fa(n + 1, vector<int> (20, 0));
    function<void(int, int)> dfs = [&](int u, int f) {
        fa[u][0] = f;
        for (auto [v, p, q] : g[u]) {
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            down[v] = down[u] + p;
            up[v] = up[u] + q;
            dfs(v, u);
        }
    };
    function<void()> init = [&]() {
        for (int j = 1; j < 20; ++ j)
            for (int i = 1; i <= n; ++ i)
                if (fa[i][j - 1] != -1) fa[i][j] = fa[fa[i][j - 1]][j - 1];
                else fa[i][j] = -1;
    };
    auto LCA = [&](int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        int d = dep[v] - dep[u];
        for (int i{}; i < 20; ++ i) if (d & (1 << i)) v = fa[v][i];
        if (u == v) return u;
        for (int i = 19; ~i; -- i) {
            if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    int s, t; cin >> s >> t;
    int lca = lca(s, t);
    int ans = up[s] - up[lca] + down[t] - down[lca];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}