#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};
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
    vector dis(n + 1, vector<vector<int>>(m + 1, vector<int> (4, 1e18)));
    priority_queue<Node> pq;
    dis[1][1][0] = t[1][1];
    int ans = 1e18;
    pq.emplace(dis[1][1][0], 1, 1, 0);
    while (!pq.empty()) {
        auto [curDis, x, y, curDir] = pq.top(); pq.pop();
        if (curDis > dis[x][y][curDir]) continue;
        if (x == n && y == m) {
            ans = min(ans, curDis + (curDir == 1) * d[x][y]);
            continue;
        }
        for (int k = 0; k < 4; ++ k) {
            int tx = x + dx[k], ty = y + dy[k];
            if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
            int cost = t[x][y];
            if (k != curDir) cost += d[x][y];
            int nxt = curDis + cost + t[tx][ty];
            if (k != curDir) nxt -= t[tx][ty];
            if (nxt < dis[tx][ty][k]) {
                dis[tx][ty][k] = nxt;
                pq.emplace(nxt, tx, ty, k);
            }
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}