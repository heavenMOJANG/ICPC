#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 510;
int fac[N], inv[N];
int qpow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
int C(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (int i = n - 1; ~i; -- i) {
        vector<int> ndp(k + 1);
        for (int a{}; a <= k; ++ a)
            for (int b{}; a + b <= k; ++ b) (ndp[a + b] += dp[a] * C((a + b + (s[i] == '0')) / 2, b) % MOD) %= MOD;
        dp.swap(ndp);
    }
    cout << dp[k] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; ~i; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}