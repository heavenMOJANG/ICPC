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
    int h, w; cin >> h >> w;
    vector g(h, vector<int> (w));
    int tot{};
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) cin >> g[i][j], tot ^= g[i][j];
    auto to = [&](int x, int y) {
        return (x - 1) * w + y;
    };
    int maxn = tot;
    for (int i{}; i < (1ll << (h * w)); ++ i) {
        int ok = 1, res{};
        for (int j{}; j < (h * w); ++ j) {
            if ((1ll << j) & i == 0) continue;
            int px = j / w - 1, py = j - px * w;
            int flag{};
            for (int k{}; k < 4; ++ k) {
                int tx = px + dx[k], ty = py + dy[k];
                if (tx < 0 || tx >= h || ty < 0 || ty >= w) continue;
                if ((1ll << to(tx, ty)) & i) flag = 1;
            }
            ok &= flag;
            res ^= g[px][py];
        }
        if (ok) maxn = max
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}