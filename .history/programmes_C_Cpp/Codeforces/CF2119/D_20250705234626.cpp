#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> dp(n + 1), ndp(n + 1), pre(n + 1), npre(n + 1);
    dp[0] = 1, pre[0] = 0;
    for (int i = 1; i <= n; ++ i) {
        fill(ndp.begin(), ndp.end(), 0);
        fill(npre.begin(), npre.end(), 0);
        for (int j{}; j < i; ++ j) {
            ndp[j] = (ndp[j] + dp[j]) % m;
            npre[j] = ((npre[j] + pre[j]) % m + dp[j] * i % m) % m;
            int res = (i * (i + 1) / 2 % m - pre[j] + m) % m;
            ndp[j + 1] = (ndp[j + 1] + res) % m;
            npre[j + 1] = ((npre[j + 1] + pre[j]) % m + res) % m;
        }
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