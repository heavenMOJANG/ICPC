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
    for (int i{}; i < n; ++ i) cin >> a[i];
    unordered_map<int, int> mp;
    for (int i{}; i < n; ++ i) mp[a[i]] ++;
    if (!d) { cout << n - mp.size() << "\n"; return; }
    unordered_map<int, vector<int>> mp1;
    for (auto [x, y] : mp) mp1[x % d].emplace_back(x);
    int tot{};
    for (auto [x, v] : mp1) {
        sort(v.begin(), v.end());
        int dp1{}, dp0{};
        for (auto vv : v) {
            int ndp1 = dp0 + mp[vv], ndp0 = max(dp1, dp0);
            dp1 = ndp1, dp0 = ndp0;
        }
        tot += max(dp1, dp0);
    }
    cout << n - tot << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}