#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n); int d{};
    for (auto && x: a) cin >> x,  d = __gcd(d, x);
    if (*min_element(a.begin(), a.end()) == d) { cout << n - count(a.begin(), a.end(), d) << "\n"; return; }
    int m = *max_element(a.begin(), a.end()) / d;
    vector<int> dp(d + 1, INF);
    dp[0] = 0;
    for (int i{}; i < n; ++ i) {
        vector ndp = dp;
        for (int j{}; j <= m; ++ j) if (dp[d] < INF) ndp[__gcd(a[i] / d, j)] = min(ndp[__gcd(a[i] / d, j)], dp[j] + 1);
        dp = ndp;
    }
    cout << dp[d] + n - 2 << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}