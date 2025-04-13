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
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end(), greater<int>());
    long double ans = max(0.0l, P * mul + mns);
    for (int i = p; i < v[1].size(); ++ i) {
        if (s[1].size() == k) break;
        if (s[0].size()) { mul /= s[0].top() * 0.1l; s[0].pop(); }
        mns -= v[1][p];
        s[1].push(v[1][p]);
        ans = min(ans, max(0.0l, P * mul + mns));
        //cout << fixed << setprecision(2) << ans << "\n";
    }
    cout << fixed << setprecision(2) << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}