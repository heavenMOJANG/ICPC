#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
S op(S a, S b) { return (a + b) % MOD; }
S e() { return 0ll; }
int qpow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    vector<int> fac(n + 1, 1), inv(n + 1);
    for (int i = 1; i <= n; ++ i) fac[i] = fac[i - 1] * 2 % MOD;
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; ~i; -- i) inv[i] = inv[i + 1] * 2 % MOD;
    segtree<S, op, e> cnt(n + 1);
    vector<int> f(n + 1, 0);
    int sum{};
    for (int i = 1; i <= n; ++ i) {
        int C = cnt.prod(0, p[i]) % MOD;
        int F = (C + fac[i - 1] * sum) % MOD;
        f[i] = F;
        (sum += C * inv[i] % MOD) %= MOD;
    }
    segtree<S, op, e> seg(n + 1);
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        int d = (seg.prod(p[i], n) + MOD) % MOD;
        (ans += d) %= MOD;
        seg.set(p[i], f[i]);
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