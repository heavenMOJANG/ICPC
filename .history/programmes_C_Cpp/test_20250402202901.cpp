#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector g(n + 1, vector<int>(n + 1, 0));
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    int q; cin >> q;
    while (q --) {
        vector<int> col(n + 1, 0);
        set<int> s;
        for (int i = 1; i <= n; ++ i) cin >> col[i], s.insert(col[i]);
        if (s.size() != k) {
            cout << "No\n";
            return
        }
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j) if (g[i][j] && col[i] == col[j]) { cout << "No\n"; return; }
        cout << "Yes\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}