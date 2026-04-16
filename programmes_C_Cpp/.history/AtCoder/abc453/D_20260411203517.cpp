#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};
constexpr char dc[4] = {'U', 'D', 'L', 'R'};
struct State { int x, y, dir; };
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
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}