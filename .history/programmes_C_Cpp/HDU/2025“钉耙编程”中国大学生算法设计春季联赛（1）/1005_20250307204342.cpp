#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
constexpr int N = 2e5 + 10;
struct Node {
    int d, x, y, dir;
    bool operator < (const Node &rhs) const {
        return d > rhs.d;
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector t(n + 1, vector<int>(m + 1)), d = t;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> t[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> d[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            
        }
    vector dis(n + 1, vector<vector<int>>(m + 1, vector<int> (4, 1e18)));
    vector<int> vis(n * m * 4 + 10, 0);
    priority_queue<Node> pq;
    dis[1][1][2] = t[1][1];
    pq.emplace(dis[1][1][2], 1, 1, 2);
    while (!pq.empty()) {
        auto [_dis, x, y, _dir] = pq.top(); pq.pop();
        if (vis[(x - 1) * n + y + n * m * _dir]) continue;
        vis[(x - 1) * n + y + n * m * _dir] = 1;
        for (int k = 0; k < 4; ++ k) {
            int tx = x + dx[k], ty = y + dy[k];
            if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
            int w = dis[x][y][_dir] + t[tx][ty] + (_dir != k) * d[x][y];
            if (w < dis[tx][ty][k]) {
                dis[tx][ty][k] = w;
                pq.emplace(w, tx, ty, k);
            }
        }
    }
    cout << min(dis[n][m][3], dis[n][m][2] + t[n][m]) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}