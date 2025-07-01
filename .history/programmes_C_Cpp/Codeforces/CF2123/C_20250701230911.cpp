#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int>a(n);
    for (auto && x : a) cin >> x;
    vector<int> mn(n), mx(n);
    mn[0] = a[0];
    for (int i = 1; i < n; ++ i) mn[i] = min(mn[i-1], a[i]);
    mx[n - 1] = a[n - 1];
    for (int i= n - 2; ~i; -- i) mx[i] = max(mx[i + 1], a[i]);
    string ans(n, '0');
    for (int i{}; i < n; ++ i) if (a[i] == mn[i] || a[i] == mx[i]) ans[i] = '1';
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}