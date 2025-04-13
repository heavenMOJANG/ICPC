#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector a(n + 1, vector<int> (k + 1, 0)), pre = a;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= k; ++ j) cin >> a[i][j], pre[i][j] = pre[i - 1][j] + a[i][j];
    vector dp(n + 1, vector<int> (k + 1));
    dp[0][0] = 0;
    for (int j = 1; j <= k; ++ j)
        for (int i = 1; i <= n; ++ i) {
            dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            for (int p = 0; p < i; ++ p) {
                int val = pre[i][j] - (p >= 1 ? pre[p][j] : 0ll);
                dp[i][j] = max(dp[i][j], dp[p][j - 1] + val);
            }
        }
    cout << dp[n][k] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}