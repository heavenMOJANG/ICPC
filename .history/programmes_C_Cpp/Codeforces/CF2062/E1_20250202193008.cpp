#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> w(n), dfn(n), low(n);
    for (auto && x : w) cin >> x;
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int idx{};
    auto dfs = [&](auto && self, int u, int fa) -> void{
        dfn[u] = ++ idx;
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }
        low[u] = idx;
    };
    dfs(dfs, 1, -1);

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}