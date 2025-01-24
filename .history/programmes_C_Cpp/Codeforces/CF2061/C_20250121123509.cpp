#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector dp(n + 1, vector<int> (2, 0));
    if (!a[1]) dp[1][0] = dp[1][1] = 1;
    else dp[1][0] = 1;
    for (int i = 2; i <= n; ++ i) {
        (dp[i][0] += dp[i - 1][1]) %= MOD;
        if (a[i] == a[i - 2] + 1) (dp[i][1] += dp[i - 1][0]) %= MOD;
        if (a[i] == a[i - 1]) (dp[i][1] += dp[i - 1][1]) %= MOD;
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}