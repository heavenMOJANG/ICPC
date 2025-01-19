#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    vector<double> p(n + 1);
    double sum{};
    for (int i = 1; i <= n; ++ i) cin >> p[i], p[i] /= 100, sum += p[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0l));
    dp[0][0] = 1.0l;
    dp[1][1] = p[1]; dp[1][0] = 1 - p[1];
    for (int i = 1; i <= n; ++ i) {
        dp[i][0] = dp[i - 1][0] * (1 - p[i]);
        for (int j = 1; j <= i; ++ j) {
            dp[i][j] = p[i] * dp[i - 1][j - 1] + (1 - p[i]) * dp[i][j - 1];
        }
    }
    cout << dp[n][n] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}