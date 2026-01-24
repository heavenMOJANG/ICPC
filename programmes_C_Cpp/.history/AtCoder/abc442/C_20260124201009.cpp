#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fa, siz;
    DSU(int n) : fa(n + 1), siz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (siz[x] < siz[y]) swap(x, y);
        fa[y] = x;
        siz[x] += siz[y];
    }
};
int C3(int n) {
    if (n < 3) return 0ll;
    return n * (n - 1) * (n - 2) / 6;
}
void solve() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        dsu.merge(u, v);
    }
    for (int i = 1; i <= n; ++ i) cout << C3(n - dsu.siz[dsu.find(i)]) << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}