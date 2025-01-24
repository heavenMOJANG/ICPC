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
    sort(a.begin(), a.end());
    vector<int> vis(n, 0);
    for (auto v : g[a[0].id]) vis[v] = 1;
    int ans{};
    for (int i = 1; i < n; ++ i) ans = max(ans, a[0].d + a[i].d - 1 - (vis[a[i].id]));
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}