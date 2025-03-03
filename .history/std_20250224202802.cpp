#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    vector<vector<int> > prea(30, vector<int> (n + 1, 0));
    vector<vector<int> > preb = prea;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < 30; ++ j) {
            if ((1ll << j) & a[i]) prea[j][i] = 1;
            if ((1ll << j) & b[i]) preb[j][i] = 1;
            (prea[j][i] += prea[j][i - 1]) %= MOD;
            (preb[j][i] += preb[j][i - 1]) %= MOD;
        }
    }
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < 30; ++ j) {
            if ((1ll << j) & a[i]) (f[i] += (n - i + 1 - preb[j][n] + preb[j][i - 1]) % MOD * (1ll << j) % MOD) %= MOD;
            else (f[i] += (preb[j][n] - preb[j][i - 1]) % MOD * (1ll << j) % MOD) %= MOD;
        }
    }
    for (int i = 1; i <= n; ++ i) (f[i] += f[i - 1]) %= MOD;
    while (q --) {
        int l, r; cin >> l >> r;
        int ans = (f[r] - f[l - 1] + MOD) % MOD;
        for (int i = 0; i < 30; ++ i) {
            int a1 = prea[i][r] - prea[i][l - 1], a0 = r - l + 1 - a1;
            int b1 = preb[i][n] - preb[i][r], b0 = n - r - b1;
            ans = (ans - (a1 * b0 + a0 * b1) % MOD * (1ll << i) % MOD + MOD) % MOD;
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("11.in","r",stdin);
    freopen("11.out","w",stdout);
    int _ = 1; cin >> _;
    while(_ --) solve();
    fclose(stdin), fclose(stdout);
    return 0;
}