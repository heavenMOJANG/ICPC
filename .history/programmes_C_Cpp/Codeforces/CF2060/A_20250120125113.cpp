#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    vector<int> a(5);
    cin >> a[0] >> a[1] >> a[3] >> a[4];
    int ans{};
    a[2] = a[0] + a[1];
    ans = max(ans, (int)(a[0] + a[1] == a[2]) + (a[1] + a[2] == a[3]) + (a[2] + a[3] == a[4]));
    a[2] = a[3] - a[1];
    ans = max(ans, (int)(a[0] + a[1] == a[2]) + (a[1] + a[2] == a[3]) + (a[2] + a[3] == a[4]));
    a[2] = a[4] - a[3];
    ans = max(ans, (int)(a[0] + a[1] == a[2]) + (a[1] + a[2] == a[3]) + (a[2] + a[3] == a[4]));
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}