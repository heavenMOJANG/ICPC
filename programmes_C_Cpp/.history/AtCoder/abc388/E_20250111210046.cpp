#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), vis(n, 0);
    int ans{}, p = 1;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < n; ++ i) {
        if (vis[i]) continue;
        while (p < n && a[p] < 2 * a[i] && vis[p]) p ++;
        if (p == n) break;
        vis[i] = vis[p] = 1;
        ans ++;
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