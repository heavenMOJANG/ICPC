#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    int l = 1e18, r = 0;
    for (int i = 1; i <= n; ++ i) cin >> a[i], l = min(l, a[i]), r = max(r, a[i]);
    auto check = [&](int x) {
        int sum = 0;
        for (int i = 1; i <= n; ++ i) sum += min(x, a[i]);
        return sum <= m;
    };
    while(l < r) {
        int mid = l + r + 1 >> 1;
        cout << mid << "\n";
        if (check(mid)) l = mid;
        else r = mid - 1;
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