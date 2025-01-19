#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> g[n + 1];
    vector<long double> a(n + 1), dp(n + 1);
    for (int i = 1, u, v, w; i < n; ++ i) {
        cin >> u >> v >> w;
        g[u].emplace_back(make_pair(v, w));
        g[v].emplace_back(make_pair(u, w));
    }
    function<void(int, int, int, int, int)> dfs = [&](int u, int f, int turn, int sum, int len) {
        if (!len) a[u] = INF;
        else a[u] = 1.0l * sum / len;
        int isLeaf = 1;
        if (turn) dp[u] = INF; else dp[u] = 0;
        for (auto [v, w] : g[u]) {
            if (v == f) continue;
            isLeaf = 0;
            dfs(v, u, turn ^ 1, sum + w, len + 1);
            if (turn) dp[u] = min(dp[u], dp[v]);
            else dp[u] = max(dp[u], dp[v]);
        }
        if (isLeaf) dp[u] = a[u];
        else dp[u] = min(dp[u], a[u]);
    };
    dfs(1, 0, 0, 0, 0);
    cout << dp[1] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}