#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fa;
    DSU (int n): fa(n) { iota(fa.begin(), fa.end(), 0); }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool same(int x, int y) { return find(x) == find(y) ? 1 : 0; }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        fa[x] = y;
    }
};
void solve() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    vector<int> g[n];
    for (int i{}; i < n; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int cc{}, ans{};
    vector<bool> vis(n, 0);
    for (int i{}; i < n; ++ i) {
        cc ++;
        if (vis[i]) ans --;
        for (auto v : g[i])
            if (v < i) {
                if (!dsu.same(i, v)) {
                    dsu.merge(i, v);
                    cc --;
                }
            } else {
                if (!vis[v]) ans ++;
                vis[v] = 1;
            }
        cout << (cc == 1 ? ans : -1ll) << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}