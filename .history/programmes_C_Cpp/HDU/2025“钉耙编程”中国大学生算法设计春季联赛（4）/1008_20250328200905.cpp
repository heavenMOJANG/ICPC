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
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    
    for (int j = 1; j <= k; ++j) {
        int max_val = INF;
        for (int i = 0; i <= n; ++i) {
            if (i >= 1) {
                if (max_val != INF) 
                    dp[i][j] = max_val + pre[i][j];
                if (dp[i - 1][j - 1] != INF)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            }
            if (i <= n - 1) {
                int candidate = (dp[i][j - 1] == INF) ? INF : (dp[i][j - 1] - pre[i][j]);
                if (candidate > max_val)
                    max_val = candidate;
            }
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