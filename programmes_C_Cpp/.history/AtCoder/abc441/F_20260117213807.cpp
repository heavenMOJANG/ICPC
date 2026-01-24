#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = LLONG_MIN;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i] >> v[i];
    vector dp1(n + 10, vector<int>(m + 10, INF));
    dp1[0][0] = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j{}; j <= m; ++ j) {
            dp1[i][j] = dp1[i - 1][j];
            if (j >= p[i] && dp1[i - 1][j - p[i]] != INF) dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - p[i]] + v[i]);
        }
    int maxn{};
    for (int j{}; j <= m; ++ j) maxn = max(maxn, dp1[n][j]);
    vector dp2(n + 10, vector<int>(m + 10, INF));
    dp2[n + 1][0] = 0;
    for (int i = n; i; -- i)
        for (int j{}; j <= m; ++ j) {
            dp2[i][j] = dp2[i + 1][j];
            if (j >= p[i] && dp2[i + 1][j - p[i]] != INF) dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - p[i]] + v[i]);
        }
    for (int i = 1; i <= n + 1; ++ i)
        for (int j{}; j <= m; ++ j) dp2[i][j] = max(dp2[i - 1][j], dp2[i][j]);
    string ans(n, 'C');
    for (int i = 1; i <= n; ++ i) {
        int f1{}, f0{};
        for (int j{}; j <= m && !f1; ++ j) {
            if (dp1[i - 1][j] == INF) continue;
            int d = m - j - p[i];
            if (d < 0) continue;
            int tot = dp1[i - 1][j] + v[i] + dp2[i + 1][d];
            if (tot == maxn) f1 = 1;
        }
        for (int j{}; j <= m && !f0; ++ j) {
            if (dp1[i - 1][j] == INF) continue;
            int d = m - j;
            int tot = dp1[i - 1][j] + dp2[i + 1][d];
            if (tot == maxn) f0 = 1;
        }
        if (f1 && !f0) ans[i - 1] = 'A';
        else if (f1 && f0) ans[i - 1] = 'B';
        else ans[i - 1] = 'C';
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}