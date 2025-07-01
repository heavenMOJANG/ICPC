#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
void solve() {
    int n, m; cin >> n >> m;
    string g[n + 1];
    for (int i = 1; i <= n; ++ i) cin >> g[i], g[i] = " " + g[i];
    vector dis(n + 1, vector<int> (m + 1, INF));
    vector vis(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; ++ i) 
        for (int j = 1; j <= m; ++ j)
        if (g[i][j] == 'E' && vis[i][j] == 0) {
            queue<pair<int, int>> q;
            dis[i][j] = 0;
            q.push({i, j});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if (vis[x][y]) continue;
                vis[x][y] = 1;
                for (int k{}; k < 4; ++ k) {
                    int tx = x + dx[k], ty = y + dy[k];
                    if (tx < 1 || tx > n || ty < 1 || ty > 1 || g[tx][ty] == '#' || g[tx][ty] == 'E' || vis[tx][ty]) continue;
                }
            }
        }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}