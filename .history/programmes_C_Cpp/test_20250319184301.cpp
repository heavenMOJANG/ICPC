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
    vector g(n + 1, vector<int> (m + 1, 0));
    vector vis = g;
    int sx, sy;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            cin >> g[i][j];
            if (g[i][j] == 2) sx = i, sy = j;
        }
    queue<array<int, 3>> q;
    q.push({sx, sy, 0});
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        for (int i = 0; i < 4; ++ i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || !g[tx][ty] ||vis[tx][ty]) continue;

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