#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int P, n, k; cin >> P >> n >> k;
    vector<int> v[2];
    for (int i = 1; i <= n; ++ i) {
        int t, p; cin >> t >> p;
        v[t].emplace_back(p);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end(), greater<int>());
    long double mul = 1, mns{};
    stack<int> s[2];
    for (auto x : v[0]) {
        if (s[0].size() == k) break;
        s[0].push(x);
        mul *= x * 0.1l;
    }
    int p{};
    for (int i = 0; i < v[1].size(); ++ i) {
        if (s[0].size() + s[1].size() == k) { p = i; break; }
        s[1].push(v[1][i]);
        mns -= v[1][i];
    }
    long double ans = max(0.0l, P * mul + mns);
    for (int i = p; i < v[1].size(); ++ i) {
        if (s[0].size() + s[1].size() == k) break;
        if (s[0].size()) { mul /= s[0].top() * 0.1l; s[0].pop(); }
        mns -= v[1][p];
        s[1].push(v[1][p]);
        ans = min(ans, max(0.0l, P * mul + mns));
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