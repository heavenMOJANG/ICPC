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
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = qpow(a + 1, b) * qpow(d + 1, c) % MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    for (int i = 1; i < N; ++ i)
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}