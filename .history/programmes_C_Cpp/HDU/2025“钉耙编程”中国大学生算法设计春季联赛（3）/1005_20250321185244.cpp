#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Edge {
    int u{}, v{}, w{};
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), g[n + 1], fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
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
        if (i - 1 >= 1) e.emplace_back(i, i - 1, 1);
        if (i + 1 <= n) e.emplace_back(i, i + 1, 1);
    }
    int ans{}, cnt{};
    for (int i = 0; i < e.size(); ++ i) {
        if (cnt == n - 1) break;
        if (findSet(e[i].u) == findSet(e[i].v)) continue;
        ans += e[i].w;
        unionSet(e[i].u, e[i].v);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}