#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w; cin >> h >> w;
    vector g(h, vector<int> (w));
    int tot{};
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) cin >> g[i][j], tot ^= g[i][j];
    for (int i{}; i < (1ll << (h * w)); ++ i) {
        int ok = 1;
        for (int j{}; j < (h * w); ++ j) {
            if ((1ll << j) & i == 0) continue;
            int px = j / w - 1, py = j - px * w;
            
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