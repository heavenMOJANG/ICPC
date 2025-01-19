#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int cur = a[0], ans = 1;
    for (int i = 1; i < n; ++ i)
        if (a[i] - cur >= x) {
            ans ++;
            cur = a[i];
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