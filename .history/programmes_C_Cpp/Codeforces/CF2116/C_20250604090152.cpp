#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5010;
int dp[N];
void solve() {
    int n; cin >> n;
    vector<int> a(n); int d{};
    for (auto && x: a) cin >> x,  d = __gcd(d, x);
    dp[0] = 0;
    for (int i{}; i < n; ++ i) {
        for (int j = 1; j <= 5000; ++ j) dp[__gcd(a[i], j)] = min(dp[__gcd(a[i], j)], dp[j] + 1);
        dp[a[i]] = 1;
    }
    cout << dp[d] + n - 2 << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}