#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {0, 1, 0, -1, 0, 2, 0, -2};
constexpr int dy[] = {1, 0, -1, 0, 2, 0, -2, 0};
void solve() {
    int n, m; cin >> n >> m;
    string s[n];
    for (int i{}; i < n; ++ i) cin >> s[i];
    vector dis(n, vector<int> (m, 0)), vis(n, vector<int> (m, 0));
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    dis[sx][sy] = 0;
    deque<pair<int, int>> dq; dq.push_front({sx, sy});
    while (dq.size()) {
        auto [x, y] = dq.front(); dq.pop_front();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int i{}; i < 8; ++ i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (s[nx][ny] == '#') continue;
            if (dis[nx][ny] > dis[x][y] + 1) {
                dis[nx][ny] = dis[x][y] + 1;
                dq.push_back({nx, ny});
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