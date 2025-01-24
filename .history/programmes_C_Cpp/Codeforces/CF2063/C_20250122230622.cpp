#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int id, d;
    bool operator < (const Node & b) const { return d > b.d; }
};
void solve() {
    int n; cin >> n;
    vector<Node> a(n);
    vector<int> g[n];
    for (int i = 0; i < n; ++ i) a[i].id = i;
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        a[u].d ++, a[v].d ++;
    }
    if (n == 2) { cout << "0\n"; return; }
    sort(a.begin(), a.end());
    int ans = a[0].d;
    vector<int> vis(n, 0);
    for (int v : g[a[0].id]) vis[v] = 1;
    for (int i = 1; i < n; ++ i) if (vis[a[i].id]) a[i].d --;
    sort(a.begin() + 1, a.end());
    if (a[1].d >= 2) ans ++;
    if (a[1].d == 0) ans --;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}