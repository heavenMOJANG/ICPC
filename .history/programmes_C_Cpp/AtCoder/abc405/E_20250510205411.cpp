#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 4e6 + 10;
int fac[N], inv[N];
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}
int C(int n, int m) {
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans{};
    for (int i{}; i <= b; ++ i)
        (ans += C(b, i) * C(a + c + i, c) % MOD) %= MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}