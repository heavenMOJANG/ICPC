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
    int ans{};
    vector<int> vis(n, 0);
    if (a[0].d == a[1].d) {
        vector b = a;
        swap(b[0], b[1]);
        int res = b[0].d;
        for (auto v : g[b[0].id]) vis[v] = 1;
        for (int i = 0; i < n; ++ i) if (vis[b[i].id]) b[i].d --;
        sort(b.begin() + 1, b.end());
        res += b[1].d - 1;
        ans = max(ans, res);
    }
    fill(vis.begin(), vis.end(), 0);
    int res = a[0].d;
    for (auto v : g[a[0].id]) vis[v] = 1;
    for (int i = 0; i < n; ++ i) if (vis[a[i].id]) a[i].d --;
    sort(a.begin() + 1, a.end());
    res += a[1].d - 1;
    cout << max(ans, res) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}