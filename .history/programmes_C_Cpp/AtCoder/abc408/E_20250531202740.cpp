#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    int n;
    vector<int> fa, rk;
    DSU(int _n): n(_n), fa(n + 1), rk(n + 1, 0) { iota(fa.begin(), fa.end(), 0); }
    int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        if (rk[x] < rk[y]) swap(x, y);
        fa[y] = x;
        if (rk[x] == rk[y]) rk[x] ++;
    }
};
struct Edge { int u, v, w; };
void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> e(m);
    for (int i{}; i < m; ++ i) cin >> e[i].u >> e[i].v >> e[i].w;
    int ans = (1ll << 30) - 1;
    for (int i = 29; ~i; -- i) {
        int cur = ans & (~(1ll << i));
        DSU dsu(n);
        for (auto [u, v, w]: e)
            if (w & (~cur) == 0) dsu.unionSet(u, v);
        if (dsu.findSet(1) == dsu.findSet(n)) ans = cur;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}