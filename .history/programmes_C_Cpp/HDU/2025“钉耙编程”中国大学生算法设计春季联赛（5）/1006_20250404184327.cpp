#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
int dp[405][405][405];
void solve() {
    int n, m, v; cin >> n >> m >> v;
    dp[0][0][0] = 1;
    vector<int> g(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> g[i];
    for (int i = 1; i <= n; ++ i)
        for (int j{}; j <= m; ++ j)
            for (int k{}; k <= v; ++ k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j > 0 && k >= g[i - 1]) {
                    (dp[i][j][k] += dp[i][j - 1][k - g[i - 1]]) %= MOD;
                }
            }
    cout << dp[n][m][v] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}