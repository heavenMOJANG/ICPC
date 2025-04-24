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
    vector<int> dep(n + 1, 1), vis(n + 1, 0);
    int s, t; cin >> s >> t;
    vector<int> path, tmp;
    function<void(int, int)> dfs = [&](int u, int fa) {
        if (u == t) {
            path = tmp;
            for (auto x : path) vis[x] = 1;
            return;
        }
        for (auto [v, p, q] : g[u]) {
            if (v == fa) continue;
            tmp.emplace_back(v);
            dfs(v, u);
            tmp.pop_back();
        }
    };
    tmp.emplace_back(s);
    dfs(s, 0);
    vector<int> dp(n + 1, 0);
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        for (auto [v, p, q] : g[u]) {
            if (v != fa && !vis[v]) {
                dfs1(v, u);
                dp[u] += max(0ll, dp[v] + p + q);
            }
        }
    }; dfs1(t, -1);
    int ans{};
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}