#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int qp(int a, int x, int mod) {
    int res = 1;
    a %= mod;
    while (x) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}
int inv(int n, int mod) { return qp(n, mod - 2, mod); }
void solve() {
    int k, m; cin >> k >> m;
    int mod = 10007;
    int invm = inv(m, mod), inv9 = inv(9, mod);
    int q{}, r{};
    for (int i{}; i < k; ++ i) {
        int c, l; cin >> c >> l;
        int mod9 = 9 * m, p = qp(10, l, mod9), pm = qp(10, l, mod);
        int t1 = (r * 9) % mod9 * p % mod9;
        int t2 = c * (p - 1 + mod9) % mod9;
        int val_M = (t1 + t2) % mod9;
        int rr = val_M / 9;
        int tm1 = (r * pm) % mod;
        int tm2 = c * (pm - 1 + mod) % mod * inv9 % mod;
        int x = (tm1 + tm2) % mod;
        int rm = rr % mod;
        int y = (x - rm + mod) % mod * invM % mod;
        q = (q * pm % mod + y) % mod;
        r = rr;
    }
    cout << q << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}