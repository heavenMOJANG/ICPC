#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};
void solve() {
    int h, w; cin >> h >> w;
    vector<string> g(h);
    for (int i{}; i < h; ++ i) cin >> g[i];
    vector<vector<int>> a(h, vector<int>(w, 0));
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) if (g[i][j] == '#') a[i][j] = -1;
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j)
            if (g[i][j] == '.') {
                int cnt{};
                for (int k{}; k < 4; ++ k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                    if (g[ni][nj] == '#') cnt ++;
                }
                a[i][j] = cnt;
            }
    vector<pair<int, int>> cur;
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) if (a[i][j] == 1) cur.emplace_back(i, j);
    while (!cur.empty()) {
        for (auto &p : cur) {
            auto [x, y] = p;
            if (a[x][y] == 1) { g[x][y] = '#'; a[x][y] = -1; }
        }
        vector<pair<int, int>> nxt;
        for (auto &p : cur) {
            auto [x, y] = p;
            if (a[x][y] != -1) continue;
            for (int k{}; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (a[nx][ny] != -1) {
                    a[nx][ny] += 1;
                    if (a[nx][ny] == 1) nxt.emplace_back(nx, ny);
                }
            }
        }
        cur.swap(nxt);
    }
    int ans{};
    for (int i = 0; i < h; ++ i)
        for (int j = 0; j < w; ++ j) if (g[i][j] == '#') ans ++;
    cout << ans << "\n";
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
