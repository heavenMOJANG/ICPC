#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end(), greater<>());
    multiset<int> s;
    int ans{}, p{};
    for (int i = n; i; -- i) {
        while (p < n && a[p].first >= i) s.insert(a[p ++].second);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}