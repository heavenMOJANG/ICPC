#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n + 1);
    vector dp(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> g[n + 1];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int f) {
        dp[u][1] = a[u];
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c);
        }
    };
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}