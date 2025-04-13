#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
int C[11][11];
void init() {
    for (int i{}; i <= 10; ++ i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], (a[i] += a[i - 1]) %= MOD;
    vector pa(n + 1, vector<int> (k + 1, 0));
    for (int i = 1; i <= n; ++ i) {
        pa[i][0] = 1;
        for (int j = 1; j <= k; ++ j) pa[i][j] = (pa[i][j - 1] * a[i]) % MOD;
    }
    int ans{};
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    init();
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}