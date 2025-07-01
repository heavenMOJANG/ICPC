#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fa;
    DSU(int _): fa(_ + 1) { iota(fa.begin(), fa.end(), 0); }
    int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
    bool unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return 0;
        fa[x] = y;
        return 1;
    }
    bool isSame(int x, int y) { return findSet(x) == findSet(y); }
};
void solve() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    int ok = 1;
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        ok &= dsu.unionSet(u, v);
    }
    cout << (ok ? "No\n" : "Yes\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}