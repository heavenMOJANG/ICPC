#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0, x; i < n; ++ i) cin >> x, mp[x] ++, s.insert(x);
    int ans{};
    for (int i = 1; i <= k / 2; ++ i) {
        if (i * 2 == k) ans += mp[i] / 2;
        else ans += min(mp[i], mp[k - i]);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}