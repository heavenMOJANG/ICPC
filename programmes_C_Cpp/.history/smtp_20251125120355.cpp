#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> t(n + 1), val(n + 1);
    int ans{};
    for (int i = 1; i <= n; ++ i) cin >> t[i];
    for (int i = 1; i <= n; ++ i) cin >> val[i], ans += val[i];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}