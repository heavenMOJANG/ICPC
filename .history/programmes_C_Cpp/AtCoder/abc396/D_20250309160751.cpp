#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void dfs(int x, int w) {

}
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < n; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> dis(n + 1, 1e18);
    function<void(int, int, int)> dfs = [&](int u, int val, int s) {
        if (u == n) {

        }
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}