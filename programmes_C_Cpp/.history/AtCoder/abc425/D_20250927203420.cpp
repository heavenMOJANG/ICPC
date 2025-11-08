#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    if (!(cin >> H >> W)) return 0;
    vector<string> g(H);
    for (int i = 0; i < H; ++i) cin >> g[i];



    // a[i][j] = -1 表示黑格；>=0 表示白格且值为当前相邻黑格数量
    vector<vector<int>> a(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (g[i][j] == '#') {
                a[i][j] = -1;
            }
        }
    }
    // 计算每个白格的邻黑数量（基于初始 g）
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (g[i][j] == '.') {
                int cnt = 0;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                    if (g[ni][nj] == '#') ++cnt;
                }
                a[i][j] = cnt;
            }
        }
    }

    vector<pair<int,int>> cur;
    cur.reserve(H * W / 4 + 4);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (a[i][j] == 1) cur.emplace_back(i, j);

    while (!cur.empty()) {
        // 1) 本轮同时染黑
        for (auto &p : cur) {
            int x = p.first, y = p.second;
            if (a[x][y] == 1) { // 保险检查
                g[x][y] = '#';
                a[x][y] = -1;
            }
        }
        // 2) 把这些格子的影响一次性应用到邻居，收集下一轮
        vector<pair<int,int>> nxt;
        nxt.reserve(cur.size() * 2 + 4);
        for (auto &p : cur) {
            int x = p.first, y = p.second;
            // 只有真正被染成黑的格子才影响邻居
            if (a[x][y] != -1) continue;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (a[nx][ny] != -1) {
                    a[nx][ny] += 1;
                    if (a[nx][ny] == 1) nxt.emplace_back(nx, ny);
                }
            }
        }
        cur.swap(nxt);
    }

    long long ans = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (g[i][j] == '#') ++ans;
    cout << ans << "\n";
    return 0;
}
