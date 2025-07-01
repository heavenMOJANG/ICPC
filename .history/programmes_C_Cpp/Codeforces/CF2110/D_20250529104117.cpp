#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> b(n);
    for (auto && x: b) cin >> x;
    vector<pair<int, int>> g[n];
    for (int i{}; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        u --, v --;
        g[u].emplace_back(v, w);
    }
    auto check = [&](int x) {
        vector<int> dp(n, 0);
        for (int u{}; u < n; ++ u) {
            if (u && !dp[u]) continue;
            dp[u] += b[u];
            dp[u] = min(dp[u], x);
            for (auto [v, w]: g[u])
                if (w <= dp[u]) dp[v] = max(dp[v], dp[u]);
        }
        return dp[n - 1] > 0;
    };
    if (!check(INF)) { cout << "-1\n"; return; }
    int l{}, r = INF;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}