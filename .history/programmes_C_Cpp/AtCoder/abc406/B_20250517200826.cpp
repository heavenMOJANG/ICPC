#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    int ans = 1, lmd = 1;
    for (int i = 1; i <= k; ++ i) lmd *= 10;
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        ans *= x;
        if (ans >= pow(10, k)) ans = 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}