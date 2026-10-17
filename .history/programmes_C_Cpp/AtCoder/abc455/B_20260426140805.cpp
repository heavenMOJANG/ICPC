#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int H, W; cin >> H >> W;
    vector<string> g(H + 1);
    for (int i = 1; i <= H; ++ i) {
        cin >> g[i];
        g[i].insert(0, " ");
    }
    int ans{};
    for (int h1 = 1; h1 <= H; ++ h1) {
        for (int h2 = h1; h2 <= H; ++ h2) {
            for (int w1 = 1; w1 <= W; ++ w1) {
                for (int w2 = w1; w2 <= W; ++ w2) {
                    bool ok = true;
                    for (int i = h1; i <= h2; ++ i) {
                        for (int j = w1; j <= w2; ++ j) {
                            if (g[i][j] != g[h1 + h2 - i][w1 + w2 - j]) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                    if (ok) ++ ans;
                }
            }
        }
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
