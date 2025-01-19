#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0;i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, maxn = 0, sum = 0;
    for (int j = 0; j < n; ++ j) {
        sum += a[j];
        while (a[j] - a[i] > 1) {
            sum -= a[i];
            i ++;
        }
        if (sum <= m) ans = max(ans, sum);
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