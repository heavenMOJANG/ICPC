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
    int maxn{};
    for (int i = 0; i < h; ++ i)
        for (int j = 0; j < w; ++ j) {
            for (int a = 0; a < h; ++ a)
                for (int b = 0; b < w; ++ b) {
                    if (a * (h - 1) + b <= i * (h - 1) + j) continue;
                    auto check = [&](int x0, int y0, int x1, int y1) {
                        int res{};
                        for (int i = 0; i < h; ++ i)
                            for (int j = 0; j < w; ++ j)
                                if (abs(i - x0) + abs(j - y0) <= d || abs(i - x1) + abs(j - y1) <= d) res ++;
                        return res;
                    };
                    maxn = max(maxn, auto(i, j, a, b));
                }
        }
    cout << maxn << "|n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}