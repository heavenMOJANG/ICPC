#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};
void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i{}; i < n; ++ i) cin >> g[i];
    vector d(n, vector<int>(m, INF));
    vector<vector<pair<int, int>>> a(26);
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) if ('a' <= g[i][j] <= 'z') a[g[i][j] - 'a'].emplace_back(i, j);
    vector<int> vis(26, 0);
    queue<pair<int, int>> q; q.push({0, 0});
    d[0][0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int dis = d[x][y];
        for (int k{}; k < 4; ++ k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#') continue;
            if (d[nx][ny] > dis + 1) {
                d[nx][ny] = dis + 1;
                q.push({nx, ny});
            }
        }
        if ('a' <= g[x][y] <= 'z') {
            int v = g[x][y] - 'a';
            if (!vis[v]) {
                vis[v] = 1;
                for (auto [nx, ny] : a[v])
                    if (d[nx][ny] > dis + 1) {
                        d[nx][ny] = dis + 1;
                        q.push({nx, ny});
                    }
            }
        }
    }
    cout << (d[n - 1][m - 1] == INF ? -1ll : d[n - 1][m - 1]) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}