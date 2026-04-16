#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int cur{}, ans{};
    for (int i{}; i < n; ++ i)
        if (cur <= a[i]) ans += a[i] - cur, cur = a[i] + 100;
    if (cur < t) ans += t - cur;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}