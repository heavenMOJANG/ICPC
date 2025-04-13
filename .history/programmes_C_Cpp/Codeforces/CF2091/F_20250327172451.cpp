#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
void solve() {
    int n, m, d; cin >> n >> m >> d;
    string a[n + 1];
    for (int i = 1; i <= n; ++ i) cin >> a[i], a[i] = " " + a[i];
    vector dp(n + 1, vector<int> (m + 1));
    vector<int> g(n + 1), h(n + 1);
    for (int i = n; i; -- i) {
        for (int j = 1; j <= m; ++ j) g[j] = (g[j - 1] + (a[i][j] == 'X' ? (i == n ? 1ll : dp[i + 1][min(m, j + d - 1)] - dp[i + 1][max(0ll, j - d)] + MOD) : 0ll)) % MOD;
        for (int j = 1; j <= m; ++ j) h[j] = (h[j - 1] + (a[i][j] == 'X' ? g[min(m, j + d)] - g[max(0ll, j - d - 1)] + MOD : 0ll)) % MOD;
        for (int j = 1; j <= m; ++ j) dp[i][j] = h[j];
    }
    cout << dp[1][m] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}