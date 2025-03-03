#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string c[n];
    for (int i = 0; i < n; ++ i) cin >> c[i];
    vector g(n, vector<int>(n, INF));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++ i) {
        q.push({i, i});
        g[i][i] = 0;
    }
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j) {
            if (i == j || c[i][j] == '-') continue;
            q.push({i, j});
            g[i][j] = 1; 
        }
    while (!q.empty()) {
        auto [u, v] = q.front(); q.pop();
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                if (c[i][u] != '-' && c[v][j] != '-' && c[i][u] == c[v][j] && g[i][j] == INF) {
                    g[i][j] = g[u][v] + 2;
                    q.push({i, j});
                }
    }
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j) cout << (g[i][j] == INF ? -1ll : g[i][j]) << " \n"[j == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}