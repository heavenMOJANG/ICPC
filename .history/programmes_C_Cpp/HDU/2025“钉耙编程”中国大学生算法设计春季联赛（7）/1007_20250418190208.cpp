#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v, p, q; cin >> u >> v >> p >> q;
        g[u].emplace_back(v, p);
        g[v].emplace_back(u, q);
    }
    vector<int> dep(n + 1, 0), siz(n + 1, 1), son(n + 1), top(n + 1), fa(n + 1), dfn(n + 1);
    function<void(int)> dfs0 = [&](int u) {
        son[u] = -1;
        for (auto [v, w] : g[u]) {
            if (!dep[v]) {
                dep[v] = dep[u] + 1;
                fa[v] = u;
                dfs0(v);
                siz[u] += siz[v];
                if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
            }
        }
    };
    dep[1] = 1;
    dfs0(1);
    int tim{};
    function<void(int, int)> dfs1 = [&](int u, int tp) {
        top[u] = tp;
        dfn[u] = ++ tim;
        if (son[u] == -1) return;
        dfs1(son[u], tp);
        for (auto [v, w] : g[u])
            if (v != son[u] && v != fa[u]) dfs2(v, v);
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}