#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
int p5[N];
int inv(int x) {
    int a = x, b = MOD, u = 1, v = 0;
    while (b) {
        int t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    if (u < 0) u += MOD;
    return u;
}
void solve() {
    int n, k;
    vector dp(n + 1, vector<int> (2, 0));
    vector<int> pre(n + 1, 0);
    dp[0][0] = 1; dp[0][1] = 0;
    pre[0] = p5[n];
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        int l = max(0ll, i - k), r = i - 1;
        int cur{};
        if (!l) cur = pre[r];
        else cur = (pre[r] - pre[l - 1] + MOD) % MOD;
        dp[i][1] = cur * inv(p5[n - i]) % MOD;
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * 21 % MOD;
        pre[i] = (pre[i - 1] + dp[i][0] * p5[n - i] % MOD) % MOD;
    }
    for (int i{}; i <= k; ++ i) (ans += dp[n - i][0] * p5[i] % MOD) %= MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    p5[0] = 1;
    for (int i = 1; i < N; ++ i) p5[i] = p5[i - 1] * 5 % MOD;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}