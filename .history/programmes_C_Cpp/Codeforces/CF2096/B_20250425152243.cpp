#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i].first;
    for (int i{}; i < n; ++ i) {
        cin >> a[i].second;
        if (a[i].first < a[i].second) swap(a[i].first, a[i].second);
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans{};
    for (int i{}; i < k - 1; ++ i) ans += a[i].first + a[i].second;
    for (int i = k - 1; i < n; ++ i) ans += a[i].first;
    cout << ans + 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}