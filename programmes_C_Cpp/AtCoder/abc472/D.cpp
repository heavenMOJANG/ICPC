#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
void solve() {
    int H, W, K; cin >> H >> W >> K;
    vector<string> S(H);
    for (auto && s : S) cin >> s;
    vector<int> r(H, 0), c(W, 0);
    for (auto i : views::iota(0, H))
        for (int j : views::iota(0, W))
            if (S[i][j] == '#') r[i] = c[j] = 1;
    vector dis(H, vector<int>(W, -1));
    queue<pair<int, int>> Q;
    for (int i : views::iota(0, H))
        for (int j : views::iota(0, W))
            if (S[i][j] == '.' && !r[i] && !c[j]) {
                dis[i][j] = 0;
                Q.push({i, j});
            }
    int ans{};
    while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        ans ++;
        if (dis[x][y] == K) continue;
        for (int k : views::iota(0, 4)) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (S[nx][ny] == '#' || dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[x][y] + 1;
            Q.push({nx, ny});
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