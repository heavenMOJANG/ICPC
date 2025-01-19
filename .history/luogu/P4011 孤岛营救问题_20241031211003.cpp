#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 15;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
struct Node {
    int x, y, step, sts;
    //Node(int _x, int _y, int _step, int _sts) : x(_x), y(_y), step(_step), sts(_sts) {}
};
int n, m, p, k, s, ans = 100;
int g[N][N][N][N], vis[N][N][1ll << N], keyNum[N][N], key[N][N][N];
queue<Node> q;
int getKeyStatus(int x, int y) {
    int res{};
    for (int i = 1; i <= keyNum[x][y]; ++ i) {
        res |= 1ll << key[x][y][i] - 1;
    }
    return res;
}
void bfs() {
    vis[1][1][getKeyStatus(1, 1)] = 1;
    q.push({1, 1, getKeyStatus(1, 1), 0});
    while (!q.empty()) {
        auto [x, y, step, sts] = q.front(); q.pop();
        if (x == n && y == m) {
            ans = step;
            return;
        }
        for (int i = 0; i < 4; ++ i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || ~g[x][y][tx][ty]) continue;
            if (g[x][y][tx][ty] && !(sts & (1ll << g[x][y][tx][ty] - 1))) continue;
            int tmp = sts | getKeyStatus(tx, ty);
            if (!vis[tx][ty][tmp]) {
                q.push({tx, ty, step + 1, tmp});
                vis[tx][ty][tmp] = 1;
            }
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> p >> k;
    for (int i = 1; i <= k; ++ i) {
        int Xi, Yi, Xj, Yj, G; cin >> Xi >> Yi >> Xj >> Yj >> G;
        if (!G) g[Xi][Yi][Xj][Yj] = g[Xj][Yj][Xi][Yi] = -1;
        else g[Xi][Yi][Xj][Yj] = g[Xj][Yj][Xi][Yi] = G;
    }
    cin >> s;
    for (int i = 1; i <= s; ++ i) {
        int Xi, Yi, Qi; cin >> Xi >> Yi >> Qi;
        key[Xi][Yi][++ keyNum[Xi][Yi]] = Qi;
    }
    //bfs();
    cout << (ans == 100 ? -1ll : ans) << "\n";
    return 0;
}