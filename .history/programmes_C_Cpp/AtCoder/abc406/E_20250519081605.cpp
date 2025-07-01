#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 60;
constexpr int MOD = 998244353;
int fac[N], inv[N], lg2[N];
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
    int ans{}, l{}, c{};
    for (int i = N - 1; ~i; -- i)
        if (n & (1ll << i)) {
            int res = C(i, k - c);
            int e = l;
            if (i) (e += (lg2[i] - 1) * (k - c) % MOD * (inv[i] * fac[i - 1] % MOD) % MOD) %= MOD;
            (ans += e * res % MOD) %= MOD;
            (l += 1ll << i) %= MOD;
            c ++;
        }
    if (c == k) (ans += n) %= MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    lg2[0] = 1;
    for (int i = 1; i < N; ++ i) lg2[i] = lg2[i - 1] * 2 % MOD;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}