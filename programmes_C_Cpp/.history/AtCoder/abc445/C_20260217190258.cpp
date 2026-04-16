#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    int n;
    vector<int> fa;
    DSU(int _n) : n(_n), fa(_n) { iota(fa.begin(), fa.end(), 0); }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }
};
void solve() {
    int n; cin >> n;
    DSU dsu(n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], dsu.merge(i, a[i]);
    for (int i = 1; i <= n; ++ i) cout << dsu.find(i) << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}