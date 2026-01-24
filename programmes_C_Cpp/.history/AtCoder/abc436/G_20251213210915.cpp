#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
int qpow(int a, int x) {
    int res = 1;
    while(x) {
        if(x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
int inv(int a) { return qpow(a, MOD - 2); }
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int k = n * (*max_element(a.begin(), a.end()) + 1);
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (auto x : a) for (int i = x; i <= k; ++ i) dp[i] = (dp[i] + dp[i - x]) % MOD;
    vector<int> p(k + 1);
    p[0] = dp[0];
    for (int i = 1; i <= k; ++ i) p[i] = (p[i - 1] + dp[i]) % MOD;
    if (m <= k) { cout << p[m] << "\n"; return; }
    int ans{};
    for (int i{}; i <= n; ++ i) {
        int num = 1, den = 1;
        for (int j{}; j <= n; ++ j) {
            if (i == j) continue;
            num = num * (m - j) % MOD;
            den = den * (i - j + MOD) % MOD;
        }
        int term = p[i] * num % MOD * inv(den) % MOD;
        (ans += term) %= MOD;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}