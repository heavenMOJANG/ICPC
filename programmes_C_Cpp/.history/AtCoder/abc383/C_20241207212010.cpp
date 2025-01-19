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
    int h, w, d; cin >> h >> w >> d;
    string g[h];
    vector<vector<int>> dis(h, vector<int>(w, -1));
    for (int i = 0; i < h; ++ i) cin >> g[i];
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++ i)
        for (int j = 0; j < w; ++ j) {
            if (g[i][j] == 'H') {
                q.push({i, j});
                dis[i][j] = 1;
            }
        }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++ i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= h || ty < 0 || ty >= w || g[tx][ty] == '#') continue;
            if (dis[tx][ty] != -1) continue; 
        }
    }
    int ans{};
    for (int i = 0; i < h; ++ i)
        for (int j = 0; j < w; ++ j) ans += stp[i][j] >= 0;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}