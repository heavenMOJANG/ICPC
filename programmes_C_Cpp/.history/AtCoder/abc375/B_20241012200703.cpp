#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    double ans = 0.0l;
    vector<pair<double, double>> a(n + 2);
    for (int i = 1; i <= n; ++ i) cin >> a[i].first >> a[i].second;
    a[n + 1] = a[0] = {0.0l, 0.0l};
    for (int i = 1; i <= n; ++ i) ans += sqrt((a[i].first - a[i + 1].first) * (a[i].first - a[i + 1].first) + (a[i].second - a[i + 1].second) * (a[i].second - a[i + 1].second));
    cout << fixed << setprecision(20) << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}