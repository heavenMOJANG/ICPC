#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
constexpr int MOD = 998244353;
int fac[N];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int maxn = *max_element(a.begin(), a.end());
    vector<int> cnt(maxn + 1, 0);
    for (int i = 0; i < n; ++ i) cnt[a[i]] ++;
    int ans{};
    for (int i = 0; i < maxn; ++ i) {
        if (!cnt[i]) continue;
        int t0 = fac[cnt[i] - 1];
        int t1 = fac[cnt[i]] - 1;
        ans = (ans + (t0 + t1) * i % MOD) % MOD;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac[0] = 1; fac[1] = 2;
    for (int i = 2; i < N; ++ i) fac[i] = (fac[i - 1] * 2) % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}