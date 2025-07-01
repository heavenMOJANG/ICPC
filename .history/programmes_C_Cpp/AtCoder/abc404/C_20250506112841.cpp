#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;

void solve() {
    int n, m; cin >> n >> m;
    int ok = 1;
    vector<int> g[n + 1], vis(n + 1, 0);
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    if (g[1].size() != 2) { cout << "No\n"; return; }
    int pre = g[1][0], cur = 1, lv = 1;
    while (1) {
        if (vis[cur]) {
            if (lv != n + 1) ok = 0;
            break;
        }
        vis[cur] = 1;
        if (g[cur] != 2) { ok = 0; break; }
        for (auto v : g[cur])
    }
    cout << (ok ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}