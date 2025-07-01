#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector h(n + 1, vector<int> (n + 1));
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) cin >> h[i][j];
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int j = 1; j <= n; ++ j) cin >> b[j];
    vector dp(n + 1, vector<int> (2, INF));
    dp[1][0] = 0, dp[1][1] = a[1];
    int ans{};
    for (int i = 1; i < n; ++ i) {
        bool f1{}, f2{}, f3{};
        for (int j = 1; j <= n; ++ j) {
            if (h[i][j] == h[i + 1][j]) f1 = 1;
            if (h[i][j] == h[i + 1][j] + 1) f2 = 1;
            if (h[i][j] == h[i + 1][j] - 1) f3 = 1;
        }
        if (f1 && f2 && f3) { cout << "-1\n"; return; }
        if (!f1) dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
        if (!f3) dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
        if (!f2) dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i + 1]);
        if (!f1) dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a[i + 1]);
    }
    ans = min(dp[n][0], dp[n][1]);
    for (int i = 1; i <= n; ++ i) dp[i][0] = dp[i][1] = INF;
    dp[1][0] = 0, dp[1][1] = b[1];
    for (int j = 1; j < n; ++ j) {
        bool f1{}, f2{}, f3{};
        for (int i = 1; i <= n; ++ i) {
            if (h[i][j] == h[i + 1][j]) f1 = 1;
            if (h[i][j] == h[i + 1][j] + 1) f2 = 1;
            if (h[i][j] == h[i + 1][j] - 1) f3 = 1;
        }
        if (f1 && f2 && f3) { cout << "-1\n"; return; }
        if (!f1) dp[j + 1][0] = min(dp[j + 1][0], dp[j][0]);
        if (!f3) dp[j + 1][0] = min(dp[j + 1][0], dp[j][1]);
        if (!f2) dp[j + 1][1] = min(dp[j + 1][1], dp[j][0] + a[j + 1]);
        if (!f1) dp[j + 1][1] = min(dp[j + 1][1], dp[j][1] + a[j + 1]);
    }
    ans += min(dp[n][0], dp[n][1]);
    if (ans > INF) cout << "-1\n";
    else cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}