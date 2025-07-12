#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> dp(n + 1), ndp(n + 1), pre(n + 1), npre(n + 1), s(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        s[i] = (s[i - 1] + i * i % m) % m;
        fill(ndp.begin(), ndp.end(), 0);
        fill(npre.begin(), npre.end(), 0);
        for (int j{}; j < i; ++ j) {
            if (!dp[j]) continue;
        swap(dp, ndp);
        swap(pre, npre);
    }
    int ans{};
    for (int i{}; i <= n; ++ i) (ans += dp[i]) %= m;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}