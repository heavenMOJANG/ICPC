#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1], d(n + 1, 0);
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        d[u] ++, d[v] ++;
    }
    if (n <= 3) { cout << "0\n"; return; }
    int cnt{};
    for (int i = 1; i <= n; ++ i) if (d[i] == 1) cnt ++;
    int maxn{};
    for (int u = 1; u <= n; ++ u) {
        int res{};
        for (int v : g[u]) if (d[v] == 1) res ++;
        maxn = max(maxn, res);
    }
    cout << cnt - maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}