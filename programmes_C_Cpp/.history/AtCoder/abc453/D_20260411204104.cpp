#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};
constexpr char dc[4] = {'U', 'D', 'L', 'R'};
struct State { int x, y, d; };
struct Prev {
    int px, py, pd;
    char move;
};
void solve() {
    int H, W; cin >> H >> W;
    vector<string> g(H);
    for (int i{}; i < H; ++ i) cin >> g[i];
    int sx, sy, gx, gy;
    for (int i{}; i < H; ++ i)
        for (int j{}; j < W; ++ j) {
            if (g[i][j] == 'S') sx = i, sy = j;
            if (g[i][j] == 'G') gx = i, gy = j;
        }
    vector vis(H, vector(W, vector<int>(4, 0)));
    vector prev(H, vector(W, vector<Prev>(4)));
    queue<State> q;
    for (int d{}; d < 4; ++ d) {
        int nx = sx + dx[d], ny = sy + dy[d];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (g[nx][ny] == '#') continue;
        vis[nx][ny][d] = 1;
        prev[nx][ny][d] = {sx, sy, -1, dc[d]};
        q.emplace(nx, ny, d);
    }
    int ed = -1;
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        if (x == gx && y == gy) { ed = d; break; }
        for (int dd{}; dd < 4; ++ dd) {
            int nx = x + dx[dd], ny = y + dy[dd];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (g[nx][ny] == '#') continue;
            char c = g[x][y];
            if (c == 'o' && dd != d) continue;
            if (c == 'x' && dd == d) continue;
            if (!vis[nx][ny][dd]) {
                vis[nx][ny][dd] = 1;
                prev[nx][ny][dd] = {x, y, d, dc[dd]};
                q.emplace(nx, ny, dd);
            }
        }
    }
    if (ed == -1) { cout << "No\n"; return; }
    string ans;
    int x = gx, y = gy, d = ed;
    while (1) {
        auto p = prev[x][y][d];
        ans.push_back(p.move);
        if (p.pd == -1) break;
        x = p.px, y = p.py, d = p.pd;
    }

    reverse(ans.begin(), ans.end());
    cout << "Yes\n";
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}