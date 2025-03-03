#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x7fffffff;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int> > g(n, vector<int>(m));
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) cin >> g[i][j];
    vector<vector<int> > vis(n, vector<int>(m, 0));
    int maxn{};
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) {
            if (g[i][j] && !vis[i][j]) {
                int cnt{};
                queue<pair<int, int> > q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    cnt += g[x][y];
                    for (int k = 0; k < 4; ++ k) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                maxn = max(maxn, cnt);
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