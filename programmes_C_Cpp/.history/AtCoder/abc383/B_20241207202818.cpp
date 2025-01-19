#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w, d; cin >> h >> w >> d;
    string g[h];
    for (int i = 0; i < h; ++ i) cin >> g[i];
    int maxn{};
    for (int i = 0; i < h * w - 1; ++ i) {
        int x0 = i / w, y0 = i % w;
        if (g[x0][y0] == '#') continue;
        for (int j = i + 1; j < h * w; ++ j) {
            int x1 = j / w, y1 = j % w;
            if (g[x1][y1] == '#') continue;
            auto check = [&]() {
                int res{};
                for (int a = 0; a < h; ++ a)
                    for (int b = 0; b < w; ++ b) {
                        if (g[a][b] == '#') continue;
                        if (abs(a - x0) + abs(b - y0) <= d || abs(a - x1) + abs(b - y1) <= d) res ++;
                    }
                return res;
            };
            cout << check() << "\n";
            maxn = max(maxn, check());
        }
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}