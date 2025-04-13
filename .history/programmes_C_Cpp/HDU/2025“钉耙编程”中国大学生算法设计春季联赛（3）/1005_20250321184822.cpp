#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Edge {
    int u{}, v{}, w{};
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), g[n + 1], fa(n + 1);
    function<int(int)> findSet = [&](int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); };
    function<void(int, int)> unionSet = [&](int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        fa[x] = y;
    };
    vector<Edge> e;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (i - a[i] >= 1) e.emplace_back(i, i - a[i], 0);
        if (i + a[i] <= n) e.emplace_back(i, i + a[i], 0);
    }
    for (int i = 1; i <= n; ++ i) {
        
    }
    int ans{}, cnt{};
    for (int i = 0; i < )
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}