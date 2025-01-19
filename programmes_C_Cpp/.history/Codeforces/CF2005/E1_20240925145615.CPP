#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l, n, m; cin >> l >> n >> m;
    vector<int> a(l + 1);
    vector b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= l; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> b[i][j];
    vector dp(l + 2, vector<vector<int>>(n + 2, vector<int> (m + 2)));
    for (int i = 0; i <= l + 1; ++ i)
        for (int j = 0; j <= n + 1; ++ j)
            for (int k = 1; k <= m + 1; ++ k) dp[i][j][k] = 0;
    for (int i = l; i >= 1; -- i) {
        for (int j = n; j >= 1; -- j)
            for (int k = m; k >= 1; -- k) {
                if (b[j][k] == a[i]) if (!dp[i + 1][j + 1][k + 1]) dp[i][j][k] = 1;
                dp[i][j][k] += dp[i][j + 1][k] + dp[i][j][k + 1] - dp[i][j + 1][k + 1];
            }
    }
    if (dp[1][1][1]) cout << "T\n";
    else cout << "N\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}