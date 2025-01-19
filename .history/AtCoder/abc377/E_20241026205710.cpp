#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<vector<int>> go(64, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++ i) go[0][i] = a[i];
    for (int i = 1; i < 64; ++ i)
        for (int j = 1; j <= n; ++ j) go[i][j] = go[i - 1][go[i - 1][j]];
    vector<int> ans(n + 1);
    iota(ans.begin() + 1, ans.begin() + 1 + n, 1);
    for (int i = 0; i < 64; ++ i)
        if (k & (1ll << i)) {
            for (int j = 1; j <= n; ++ j) ans[j] = go[i - 1][ans[j] - 1];
        }
    for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}