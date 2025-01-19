#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++ i) cin >> x[i] >> y[i];
    int ans = 4 * m;
    for (int i = 1; i < n; ++ i) {
        if (i != n - 1) ans += 4 * m - (m - x[i]) - (m - y[i]) - (m - x[i + 1]) - (m - y[i + 1]);
        if (i == n - 1) ans += 4 * m - (m - x[i]) - (m - y[i]);
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