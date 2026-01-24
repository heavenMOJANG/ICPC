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
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto && x : p) cin >> x, x --;
    segtree<S, op, e> slu(n + 1), sld(n + 1), sru(n + 1), srd(n + 1);
    vector<int> dlu(n), dld(n), dru(n), drd(n);
    for (int i{}; i < n; ++ i) {
        dlu[i] = (slu.prod(0, p[i]) + 1) % MOD;
        dld[i] = sld.prod(p[i] + 1, n);
        slu.set(p[i], (slu.get(p[i]) + dlu[i]) % MOD);
        sld.set(p[i], (sld.get(p[i]) + dld[i] + 1) % MOD);
    }
    for (int i = n - 1; ~i; -- i) {
        dru[i] = (sru.prod(p[i] + 1, n) + 1) % MOD;
        drd[i] = srd.prod(0, p[i]);
        sru.set(p[i], (sru.get(p[i]) + dru[i]) % MOD);
        srd.set(p[i], (srd.get(p[i]) + drd[i] + 1) % MOD);
    }
    int ans{};
    for (int i{}; i < n; ++ i) (ans += dlu[i] * drd[i] % MOD) %= MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}