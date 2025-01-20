#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; ++ i) cin >> x[i];
    sort(x.begin(), x.end());
    int ans{}, sum{};
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++ i) {
        if (vis[i]) continue;
        int p = lower_bound(x.begin() + i + 1, x.end(), k - x[i]) - x.begin() - i - 1;
        if (p == n || x[p] + x[i] != k) { vis[i] = 1; sum ++; continue; }
        ans ++;
        vis[i] = vis[p] = 1;
    }
    if (sum & 1) cout << "0\n";
    else cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}