#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
void solve() {
    int H, W; cin >> H >> W;
    vector<string> g(H);
    vector vis(H, vector<int> (W, 0));
    for (int i{}; i < H; ++ i) cin >> g[i];
    int ans{};
    for (int i{}; i < H; ++ i) {
        for (int j{}; j < W; ++ j) {
            if (g[i][j] == '#' || vis[i][j]) continue;
            queue<pair<int, int>> q; q.push({i, j});
            vis[i][j] = 1;
            int flag{};
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if (x == 0 || x == H - 1 || y == 0 || y == W - 1) flag = 1;
                for (int k{}; k < 4; ++ k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if (g[nx][ny] == '#') continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            if (!flag) ans ++;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}