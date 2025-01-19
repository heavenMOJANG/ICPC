#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
int n, m, k, step[11][11], vis[11][11], ans;
char g[11][11];
void bfs(int sx, int sy) {
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) vis[i][j] = step[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (!q.empty()) {
        
    } 
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> g[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (g[i][j] == '.') bfs(i, j);
    return 0;
}