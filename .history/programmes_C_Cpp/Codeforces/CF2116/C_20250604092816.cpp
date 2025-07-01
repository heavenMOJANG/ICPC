#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n); int g{};
    for (auto && x: a) cin >> x,  g = __gcd(g, x);
    if (*min_element(a.begin(), a.end()) == g) { cout << n - count(a.begin(), a.end(), g) << "\n"; return; }
    int m = *max_element(a.begin(), a.end()) / g;
    vector<int> dp(m + 1, INF);
    dp[0] = 0;
    for (int i{}; i < n; ++ i) {
        vector ndp = dp;
        for (int j{}; j <= m; ++ j) if (dp[j] < INF) ndp[__gcd(a[i] / g, j)] = min(ndp[__gcd(a[i] / g, j)], dp[j] + 1);
        dp = ndp;
    }
    cout << dp[1] + n - 2 << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}