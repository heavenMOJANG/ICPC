#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    int ans = 0;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++ i) cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++ i) {
        if (i != 0 && i != n - 1) ans += 4 * m - x[i] - y[i] - x[i + 1] - y[i + 1];
        if (i == 0) ans += 4 * m - x[0] - y[0];
        if (i == n - 1) ans += 4 * m - x[n - 1] - y[n - 1];
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}