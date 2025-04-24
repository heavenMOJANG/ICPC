#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> dp(m + 1, 0), a(n + 1);
    vector ch(n + 1, vector<bool>(m + 1, 0));
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<int>());
    for (int i = 1; i <= n; ++ i)
        for (int j = m; j >= a[i]; -- j) {
            if (dp[j] <= dp[j - a[i]] + a[i]) {
                ch[i][j] = 1;
                dp[j] = dp[j - a[i]] + a[i];
            }
        }
    if (dp[m] != m) { cout << "No Solution"; return; }
    vector<int> ans;
    while (m) {
        if (ch[n][m]) {
            ans.emplace_back(a[n]);
            m -= a[n];
        }
        n --;
    }
    for (int i{}; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}