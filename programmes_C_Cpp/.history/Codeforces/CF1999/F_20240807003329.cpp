#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int mod = 1e9 + 7;
constexpr int N = 2e5 +10;
int fac[N], inv[N];
int fastPow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}
int C (int n, int m) {
    if (m > n) return 0ll;
    if (m == 0) return 1ll;
    return fac[n] * inv[m] % mod * inv[n - m] % mod; 
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    if (k == 1) {cout << n << "\n"; return;}
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
        if (i <= k / 2 || i + k / 2 > n) continue;
        if (a[i] == 1) ans = (ans + C(i - 1 - pre[i - 1], k / 2) * (pre[n] - pre[i], k / 2)) % mod;
    }
    ans = ans * (k / 2 + 1) % mod;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = fastPow(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; -- i) inv[i] = inv[i + 1] * (i + 1) % mod;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}