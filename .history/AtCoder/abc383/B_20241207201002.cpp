#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w, d; cin >> h >> w >> d;
    vector<vector<char>> g(h, vector<char>(h));
    for (int i = 0; i < h; ++ i)
        for (int j = 0; j < w; ++ j) cin >> g[i][j];
    for (int i = 0; i < h; ++ i)
        for (int j = 0; j < w; ++ j) {
            vis[i][j]
            for (int a = 0; a < h; ++ a)
                for (int b = 0; b < w; ++ b) {
                    if (a * (h - 1) + b <= i * (h - 1) + j) continue;
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