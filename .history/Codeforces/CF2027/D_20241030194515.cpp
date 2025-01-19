#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = LLONG_MAX;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= m; ++ i) cin >> b[i];
    if (*max_element(a.begin() + 1, a.end()) > *max_element(b.begin() + 1, b.end())) { cout << "-1\n"; return;}
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) pre[i] = pre[i - 1] + a[i];
    vector dp(n + 1, vector<int>(m + 1, INF)), minn(n + 1, vector<int>(m + 1, INF));
    fill(dp[0].begin(), dp[0].end(), 0);
    fill(minn[0].begin(), minn[0].end(), 0);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (a[i] > b[j]) continue;
            int l = 1, r = i;
            while (l < r) {
                int mid = l + r >> 1;
                if (pre[i] - pre[mid - 1] >= b[j]) r = mid;
                else l = mid + 1;
            }
            dp[i][j] = min(dp[i][j], minn[l - 1][j] + m - j);
        }
        for (int j = 1; j <= m; ++ j) minn[i][j] = min(minn[i][j - 1], dp[i][j]);
    }
    int ans = INF;
    for (int i = 1; i <= m; ++ i) ans = min(ans, dp[n][i]);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}