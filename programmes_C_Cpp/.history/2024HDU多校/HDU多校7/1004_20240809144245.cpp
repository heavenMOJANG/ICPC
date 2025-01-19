#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, s, r1, r2; cin >> n >> s >> r1 >> r2;
    vector<pair<int, int>> g[n + 1];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v, 1);
        g[v].emplace_back(u, 1);
    }
    if (r2 < 2 * r1) {cout << "Kangaroo_Splay\n"; return;}
    vector<int> dis(n + 1, 0);
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
        dis[u] = d;
        for (auto [v, w] : g[u]) {
            if (v == fa) continue;
            dfs(v, u, d + w);
        }
    };
    dfs(1, -1, 0);
    s = 1;
    for (int i = 1; i <= n; ++ i) if (dis[i] > dis[s]) s = i;
    dfs(s, - 1, 0);
    int t = 1;
    for (int i = 1; i <= n; ++ i) if (dis[i] > dis[t]) t = i;
    if (dis[t] < r2) cout << "Kangaroo_Splay\n";
    else cout << "General_Kangaroo\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}