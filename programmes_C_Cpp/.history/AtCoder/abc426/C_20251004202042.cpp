#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fa, sz;
    DSU(int n, bool ok) : fa(n + 1) { 
        iota(fa.begin(), fa.end(), 0);
        if (ok) sz.resize(n + 1, 1);
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            fa[x] = y;
            if (!sz.empty()) sz[y] += sz[x], sz[x] = 0;
        }
    }
};
void solve() {
    int n, q; cin >> n >> q;
    DSU dsu0(n, 1), dsu1(n, 0);
    while (q --) {
        int x, y; cin >> x >> y;
        int cnt{}, fy = dsu0.find(y);
        for (int i = dsu1.find(1); i <= x; i = dsu1.find(i + 1)) {
            int fi = dsu0.find(i);
            if (fi != fy) {
                cnt += dsu0.sz[fi];
                dsu0.unite(fi, fy);
            }
            dsu1.fa[i] = dsu1.find(i + 1);
        }
        cout << cnt << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}