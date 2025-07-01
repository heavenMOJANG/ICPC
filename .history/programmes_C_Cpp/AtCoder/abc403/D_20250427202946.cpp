#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<pair<int, int>> v;
    for (auto x : a)
        if (v.empty() || v.back().first != x) v.emplace_back(x, 1);
        else v.back().second ++;
    if (!d) { cout << n - v.size() << "\n"; return; }
    int tot{}, dp1{}, dp0{}, val = v[0].first - d - 1;
    for (auto [x, y] : v) {
        if (x - val != d) {
            tot += max(dp1, dp0);
            dp1 = dp0 = 0;
        }
        int ndp1 = dp0 + y, ndp0 = max(dp1, dp0);
        dp1 = ndp1, dp0 = ndp0;
        val = x;
    } 
    tot += max(dp1, dp0);
    cout << n - tot << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}