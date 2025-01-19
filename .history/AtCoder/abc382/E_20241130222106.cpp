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
    for (int i = 1; i <= n; ++ i) cin >> p[i], p[i] /= 100;
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 1.0l;
    for (int i = 1; i <= n; ++ i)
        for (int j = 0; j <= i; ++ j)
            dp[i][j] = (!j ? 0 : p[i] * dp[i - 1][j - 1]) + (1 - p[i]) * dp[i - 1][j];
    vector<double> f(x + 1, 0);
    for (int i = 1; i <= x; ++ i) {
        for (int j = 1; j <= n; ++ j) f[i] += f[max(i - j, 0ll)] * dp[n][j];
        f[i] = (f[i] + 1) / (1 - dp[n][0]);
    }
    cout << fixed << setprecision(16) << f[x] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}