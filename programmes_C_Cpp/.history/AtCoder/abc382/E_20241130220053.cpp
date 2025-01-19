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
    vector<double> p(n);
    double sum{};
    for (int i = 0; i < n; ++ i) cin >> p[i], p[i] /= 100, sum += p[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 0.0;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= i; ++ j) {
            dp[i][j] = p[i - 1] * dp[i - 1][j - 1] + (1 - p[i - 1]) * dp[i][j - 1];
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