#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};
void solve() {
    int h, w; cin >> h >> w;
    vector g(h + 1, vector<char> (w + 1));
    vector a(h + 1, vector<int> (w + 1, 0));
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                a[i][j] = -1;
                for (int k{}; k < 4; ++ k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 1 || nx > h || ny < 1 || ny > w) continue;
                    if (a[nx][ny] != -1) a[nx][ny] ++;
                }
            }
        }
    vector vis(h + 1, vector<int> (w + 1, 0));
    queue<int> q;
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j) if (a[i][j] == 1) q.push(i * w + j);
    while (!q.empty()) {
        int p = q.front(); q.pop();
        int x = p / w, y = p % w;
        if (!y) x --, y = w;
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        g[x][y] = '#';
        a[x][y] = -1;
        for (int k{}; k < 4; ++ k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > h || ny < 1 || ny > w) continue;
            if (a[nx][ny] != -1) a[nx][ny] ++;
            if (a[nx][ny] == 1) q.push(nx * w + ny);
        }
    }
    int ans{};
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j)
            if (g[i][j] == '#') ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}