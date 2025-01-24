#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum{};
    for (int i = 0; i < n; ++ i) cin >> a[i], sum += a[i];
    if (sum != (n + 1) * n / 2) { cout << "-1\n"; return; }
    sort(a.begin(), a.end());
    int ans{};
    for (int i = 0; i < n; ++ i) ans += max(0ll, i + 1 - a[i]);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}