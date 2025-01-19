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

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    if (k == 1) {cout << pre[n] << "\n"; return;}
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
        if (i <= k / 2 || i + k / 2 > n) continue;
        ans += 
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}