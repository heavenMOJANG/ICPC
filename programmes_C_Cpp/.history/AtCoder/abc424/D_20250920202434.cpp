#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w; cin >> h >> w;
    vector g(h, vector<char> (w));
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) cin >> g[i][j];
    vector<int> a(h, 0);
    int tot{};
    for (int i{}; i < h; ++ i) {
        int b{};
        for (int j{}; j < w; ++ j) if (g[i][j] == '#') b |= 1 << j, tot ++;
        a[i] = b;
    }
    int m = 1 << w;
    vector<int> dp(m, -INF), ndp(m, -INF);
    for (int j{}; j < m; ++ j) {
        if ((j & ~a[0]) != 0) continue;
        dp[j] = __builtin_popcount(j);
    }
    for (int i = 1; i < h; ++ i) {
        fill(ndp.begin(), ndp.end(), -INF);
        for (int j{}; j < m; ++ j) {
            if (dp[j] < 0) continue;
            for (int k{}; k < m; ++ k) {
                if ((k & ~a[i]) != 0) continue;
                if (((j & (j >> 1)) & (k & (k >> 1))) != 0) continue;
                ndp[k] = max(ndp[k], dp[j] + __builtin_popcount(k));
            }
        }
        dp.swap(ndp);
    }
    int cnt{};
    for (int j{}; j < m; ++ j) cnt = max(cnt, dp[j]);
    cout << tot - cnt << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}