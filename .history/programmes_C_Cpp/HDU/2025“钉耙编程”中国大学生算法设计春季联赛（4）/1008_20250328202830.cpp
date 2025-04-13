#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> pre(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            cin >> a[i][j];
            pre[j][i] = pre[j][i - 1] + a[i][j];
        }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
    dp[0][0] = 0;
    for (int j = 1; j <= k; ++ j) dp[0][j] = 0;
    for (int j = 1; j <= k; ++j) {
        int maxn = dp[0][j - 1] - pre[j][0];
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = maxn + pre[j][i];
            if (i < n) maxn = max(maxn, dp[i][j - 1] - pre[j][i]);
        }
    }
    cout << dp[n][k] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}