#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector a(n + 1, vector<int> (n + 1, 0));
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        a[u][v] = a[v][u] = 1;
    }
    set<int> black, white;
    white.insert(1);
    function<void(int, int, int)> dfs = [&](int u, int fa, int clr) {
        for ()
    };
    dfs(1, 0);

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}