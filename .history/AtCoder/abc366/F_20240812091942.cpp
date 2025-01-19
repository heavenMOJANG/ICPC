#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(),[](const pair<int, int> & x, const pair<int, int> & y) {
        return x.second * (y.first - 1) > y.second * (x.first - 1);});
    vector<int> dp(k + 1, -inf);
    int res = 1;
    for (int i = n - 1; i >= n - k; -- i) res = f(res, a[i].first, a[i].second);
    cout << res << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}