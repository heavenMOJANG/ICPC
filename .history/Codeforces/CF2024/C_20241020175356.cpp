#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i].first >> a[i].second;
    auto cmp = [&](pair<int, int> u, pair<int, int> v) {
        int invU{}, invV{};
        invU = (u.first > v.first) + (u.first > v.second) + (u.second > v.first) + (u.second > v.second);
        invV = (v.first > u.first) + (v.first > u.second) + (v.second > u.first) + (v.second > u.second);
        return invU < invVl
    };
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; ++ i) cout << a[i].first << " " << a[i].second << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}