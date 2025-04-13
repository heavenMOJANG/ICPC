#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for (int i = 0; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    set<int> white, black;
    white.insert(1);
    vector<int> vis(n + 1, 0);
    vis[1] = 1;
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto v : g[u])
    };
    dfs(1, 0, 1);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}