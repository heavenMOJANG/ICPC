#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int ans{};
    function<int(int, int)> dfs = [&](int u, int p) {
        int tot = x[u];
        for (auto [v, w] : g[u]) {
            if (v == p) continue;
            int res = dfs(v, u);
            ans += abs(res) * w;
            tot += res;
        }
        return tot;
    };
    dfs(1, 0);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}