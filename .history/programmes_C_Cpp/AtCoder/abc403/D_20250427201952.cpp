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
    int cnt{};
    for (auto [x, v] : mp1) {
        sort(v.begin(), v.end());
        int pre0{}, pre1{};
        for (auto vv : v) {
            int tmp = mp[vv], cur0 = pre1 + tmp, cur1 = max(pre0, pre1);
            pre0 = cur0, pre1 = cur1;
        }
        cnt += max(pre0, pre1);
    }
    cout << n - cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}