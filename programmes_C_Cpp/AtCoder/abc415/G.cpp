#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> e(m);
    for (auto && [a, b] : e) cin >> a >> b;
    vector<int> dp(601, 0);
    for (int i = 1; i <= 600; ++ i) {
        dp[i] = 0;
        for (auto [a, b] : e) {
            if (i >= a) dp[i] = max(dp[i], dp[i - a + b] + b);
        }
    }
    int tot = n, num = n;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}