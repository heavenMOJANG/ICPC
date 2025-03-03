#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> l(n + 1), r(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> l[i] >> r[i];
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int ans{};
    function<void(int, int)> dfs = [&](int u, int fa) {
        int res = l[u];
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            res = max(res, a[v]);
        }
        a[u] = min(res, r[u]);
        for (auto v : g[u]) ans += max(0ll, a[v] - a[u]);
    };
    dfs(1, 0);
    cout << ans + a[1] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}