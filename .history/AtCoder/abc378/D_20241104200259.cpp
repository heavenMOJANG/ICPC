#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
int n, m, k, step[11][11], ans;
char g[11][11];
void dfs(int sx, int sy) {
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) step[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    step[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++ i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || step[tx][ty] || g[tx][ty] == '#') continue;
            step[tx][ty] = step[x][y] + 1;
            q.push({tx, ty});
        }
    }
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cout << step[i][j] << " \n"[j == m];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) if (step[i][j] == k + 1) ans ++;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> g[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (g[i][j] == '.') dfs(i, j);
    cout << ans << "\n";
    return 0;
}