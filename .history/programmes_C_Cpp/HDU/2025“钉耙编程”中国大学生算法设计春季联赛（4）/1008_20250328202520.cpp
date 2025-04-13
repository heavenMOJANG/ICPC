#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = LLONG_MIN;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> pre(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + a[i][j];
        }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++ i) dp[i][0] = INF;
    for (int j = 1; j <= k; ++ j) dp[0][j] = 0;
    for (int j = 1; j <= k; ++j) {
        int maxn = dp[0][j - 1] - pre[0][j];
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = maxn + pre[j][i];
            if (i < n) maxn = max(maxn, dp[i][j - 1] - pre[i][j]);
        }
    }
    cout << dp[n][k] << "\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}