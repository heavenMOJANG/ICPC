#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(b), c(n);
    for (int i = 0; i < n; ++ i) cin >> a[i], b[i] = c[i] = a[i];
    sort(b.begin(), b.end());
    sort(c.begin(), c.end(), greater<int>());
    int ans{};
    for (int i = 0; i < n; ++ i) ans += c[0] - b[0];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}