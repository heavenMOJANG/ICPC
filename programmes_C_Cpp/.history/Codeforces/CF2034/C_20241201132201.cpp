#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string g[n + 1];
    for (int i = 1; i <= n; ++ i) cin >> g[i], g[i] = " " + g[i];
    vector<pair<int, int>> acc[n + 2][m + 2];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            switch (g[i][j]) {
                case 'U':acc[i - 1][j].emplace_back(i, j); break;
                case 'D':acc[i + 1][j].emplace_back(i, j); break;
                case 'L':acc[i][j - 1].emplace_back(i, j); break;
                case 'R':acc[i][j + 1].emplace_back(i, j); break;

            }
        }
    vector vis(n + 2, vector<int>(m + 2, 0));
    queue<pair<int, int>> q;
    for (int j = 0; j <= m + 1; ++ j) vis[0][j] = vis[n + 1][j] = 1, q.push({0, j}), q.push({n + 1, j});
    for (int i = 1; i <= n; ++ i) vis[i][0] = vis[i][m + 1] = 1, q.push({i, 0}), q.push({i, m + 1});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [tx, ty] : acc[x][y])
            if (!vis[tx][ty]) {
                vis[tx][ty] = 1;
                q.push({tx, ty});
            }
    }
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (g[i][j] == '?' && vis[i][j - 1] && vis[i - 1][j] && vis[i][j + 1] && vis[i + 1][j]) vis[i][j] = 1;
    int ans = n * m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) if (vis[i][j]) ans --;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}