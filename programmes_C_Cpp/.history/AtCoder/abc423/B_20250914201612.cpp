#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    b[0] = b[n] = 1;
    for (int i = 1; i <= n; ++ i)
        if (!a[i]) b[i] ++;
        else break;
    for (int i = n; i >= 1; -- i)
        if (!a[i]) b[i - 1] ++;
        else break;
    int ans{};
    for (int i{}; i <= n; ++ i) if (!b[i]) ans ++;
    cout << ans;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}