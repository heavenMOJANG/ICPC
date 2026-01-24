#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
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
    if (!(cin >> n)) return;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    if (n < 3) { cout << 0 << "\n"; return; }
    vector<int> fac(n + 1, 1), inv(n + 1);
    for (int i = 1; i <= n; ++ i) fac[i] = fac[i - 1] * 2 % MOD;
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; ~i; -- i) inv[i] = inv[i + 1] * 2 % MOD;
    int inv2 = qpow(2, MOD - 2);
    segtree<S, op, e> segL(n + 1), segR(n + 1);
    vector<int> l(n + 1);
    for (int i = 1; i <= n; ++i) {
        l[i] = segL.prod(0, p[i]);
        segL.set(p[i], 1);
    }
    vector<int> r(n + 1);
    for (int i = n; i; -- i) {
        r[i] = segR.prod(0, p[i]);
        segR.set(p[i], 1);
    }

    int ans{}, sum{};
    for (int i = 1; i <= n; ++ i) {
        int res = l[i] * r[i] % MOD;
        (ans += res) %= MOD;
        if (j > 1) {
            // 计算当前 j 作为右端点的贡献
            int factor = r[j] * fac[j] % MOD * inv2 % MOD; // r[j] * 2^(j-1)
            int ways = factor * sum_term % MOD;
            ans = (ans + ways) % MOD;
        }

        // 将当前的 j 作为未来可能的 i 加入到 sum_term 中
        int current_i_val = l[j] * inv[j] % MOD;
        sum_term = (sum_term + current_i_val) % MOD;
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}