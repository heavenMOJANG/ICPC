#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, L; cin >> n >> m >> L;
    vector<int> l(n), r(n);
    vector<pair<int, int>> a(m);
    for (int i = 0; i < n; ++ i) cin >> l[i] >> r[i];
    for (int i = 0; i < m; ++ i) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}