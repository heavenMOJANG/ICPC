#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, l, S, T; cin >> n >> m >> l >> S >> T;
    vector<pair<int, int>> g[n];
    for (int i{}; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }
    vector<int> end(n + 1, 0);
    function<void(int, int, int)> dfs = [&](int u, int lv, int sum) {
        if (sum >= T) return;
        if (lv == l) {
            if (S <= sum && sum <= T) end[u] = 1;
            return;
        }
        for (auto [v, w] : g[u]) dfs(v, lv + 1, sum + w);
    };
    dfs(1, 0, 0);
    vector<int> ans;
    for (int i = 1; i <= n; ++ i) if (end[i]) ans.emplace_back(i);
    for (int i{}; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}