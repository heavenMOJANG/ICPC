#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i += 2)
        if (a[i] - a[i - 1] <= k) {
            k -= a[i] - a[i - 1];
        } else ans += a[i] - a[i - 1];
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}