#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n; cin >> n;
    int pre{};
    vector<int> dp(n + 1);
    for (int i = n; i >= 1; -- i) {
        dp[i] = (i * pre % MOD + 1) % MOD;
        pre = (pre + dp[i]) % MOD;
    }
    int ans = n - 1;
    for (int k = 3; k <= n; ++ k) {
        int tmp = ((k - 1) * (k - 2) / 2 - 1 + MOD) % MOD;
        ans = (ans * tmp * dp[k] % MOD) % MOD;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}