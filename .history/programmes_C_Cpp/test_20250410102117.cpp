#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e8;
void solve() {
    int n, f; cin >> n >> f;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector dp(n + 1, vector<int> (f + 1, 0));
    for (int i = 1; i <= n; ++ i) {
        dp[i][a[i]] ++;
        for (int j{}; j < f; ++ j) {
            (dp[i][j] += dp[i - 1][j]) %= MOD;
            (dp[i][(j + a[i]) % f] += dp[i - 1][j])%= MOD;
        }
    }
    cout << dp[n][0] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}