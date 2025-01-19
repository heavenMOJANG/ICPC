#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
int n, m, k, ans, vis[11][11];
char g[11][11];
void dfs(int x, int y, int step) {
    if (step == k) { ans ++; return; }
    for (int i = 0; i < 4; ++ i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] || g[tx][ty] == '#') continue;
        vis[tx][ty] = 1;
        dfs(tx, ty, step + 1);
        vis[tx][ty] = 0;
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> g[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (g[i][j] == '.') {
                vis[i][j] = 1;
                dfs(i, j, 0);
                vis[i][j] = 0;
            }
    cout << ans << "\n";
    return 0;
}