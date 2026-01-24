#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i{}; i < n; ++ i) cin >> a[i];
    for (int i{}; i < m; ++ i) cin >> b[i];
    sort(b.begin(), b.end());
    vector<int> p(m + 1, 0);
    for (int i{}; i < m; ++ i) p[i + 1] = (p[i] + b[i]) % MOD;
    int ans{};
    for (int i{}; i < n; ++ i) {
        int x = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        int l = (a[i] * x % MOD - p[x] + MOD) % MOD;
        int r = ((p[m] - p[x] + MOD) % MOD - a[i] * (m - x) % MOD + MOD) % MOD;
        (ans += l + r) %= MOD;
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