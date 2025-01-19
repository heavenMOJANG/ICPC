#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int mod = 1e9 + 7;
void solve() {
    int l, r, k; cin >> l >> r >> k;
    if (k >= 10) {cout << "0\n"; return;}
    int d = 9 / k + 1;
    function<int(int, int)> qpow = [&](int a, int x) {
        int res = 1;
        while (x) {
            if (x & 1) res = res * a % mod;
            a = a * a % mod;
            x >>= 1;
        }
        return res;
    };
    int ans = qpow(qpow(2, d), r) - qpow(qpow(2, d), l);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}