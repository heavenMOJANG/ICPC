#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int P, n, k; cin >> P >> n >> k;
    vector<int> pre[2];
    pre[0].emplace_back(0);
    pre[1].emplace_back(0);
    for (int i = 1; i <= n; ++ i) {
        int t, p; cin >> t >> p;
        pre[t].emplace_back(p);
    }
    sort(pre[0].begin(), pre[0].end());
    sort(pre[1].begin(), pre[1].end(), greater<int>());
    
    cout << fixed << setprecision(2) << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}