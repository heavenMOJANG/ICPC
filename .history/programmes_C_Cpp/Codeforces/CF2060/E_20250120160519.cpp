#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
template <class T>
struct DSU {
    int n;
    vector<T> f, siz;
    DSU (int len) : n(len), f(len + 1), siz(len + 1, 1) { iota(f.begin(), f.end(), 0); }
    T find(T x) { return f[x] == x ? x : f[x] = findSet(f[x]); }
    void union(T x, T y) {
        x = find(x), y = find(y);
        if (isSame(x, y)) return;
        if (siz[x] >= siz[y]) f[y] = x, siz[x] += siz[y];
        else f[x] = y, siz[y] += siz[x];
    }
    bool isSame(T x, T y) { return x == y; }
};
void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<int> f[n + 1], g[n + 1];
    DSU<int> F(n), G(n);
    for (int i = 0; i < m1; ++ i) {
        int u, v; cin >> u >> v;
        f[u].emplace_back(v);
        f[v].emplace_back(u);
        F.union(u, v);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}