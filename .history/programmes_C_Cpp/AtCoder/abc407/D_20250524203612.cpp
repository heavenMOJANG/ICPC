#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w; cin >> h >> w;
    vector<int> g(h * w);
    int tot{};
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) cin >> g[i * w + j];
    int maxn{};
    function<void(int, int)> dfs = [&](int mask, int cur) {
        int b{};
        while (b < h * w && (mask & (1ll << b))) b ++;
        if (b == h * w) { maxn = max(maxn, tot ^ cur); return; }
    };
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}