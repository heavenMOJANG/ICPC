#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int j = 0; j < 2; ++ j)
        for (int i = 0; i < n; ++ i) cin >> a[i][j];
    int res{}, ans = LLONG_MIN;
    for (int i = 0; i < n; ++ i)
        if (a[i][0] > a[i][1]) res += a[i][0];
        else res += a[i][1];
    for (int i = 0; i < n; ++ i)
        if (a[i][0] > a[i][1]) {
            res += a[i][1];
            ans = max(ans, res);
            res -= a[i][1];
        } else {
            res += a[i][0];
            ans = max(ans, res);
            res -= a[i][0];
        }
    cout << ans << "\n";.
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}