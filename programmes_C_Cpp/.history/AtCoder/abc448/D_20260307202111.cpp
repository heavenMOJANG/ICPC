#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), g[n + 1], ans(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    map<int, int> mp;
    for (int i{}; i < n - 1; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int clk{};
    function<void(int, int)> dfs = [&](int u, int f) {
        cnt[a[u]] ++;
        if (cnt[a[u]] == 2) clk ++;
        ans[u] = clk;
        for (int v : g[u]) {
            if (v == f) continue;
            dfs(v, u);
        }
        if (cnt[a[u]] == 2) clk --;
        cnt[a[u]] --;
    };
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i) cout << (ans[i] ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}