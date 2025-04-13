#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), L(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> pre(32, 0);
    for (int i = 1; i <= n; ++ i) {
        cin >> L[i];
        int cnt{};
        L[i] = min(L[i], a[i]);
        pre[0] = 1ll << (a[i] & 1);
        for (int j = 1; j <= 30; ++ j) pre[j] = (pre[j - 1] << ((a[i] >> j) & 1)) % MOD;
        for (int j = 30; j >= 0; -- j) {
            if ((L[i] >> j) & 1) {

            } else if (!j) (cnt += 1) %= MOD;
        }
    }
    int ans = 1;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}