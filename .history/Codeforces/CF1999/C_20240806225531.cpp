#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, s, m; cin >> n >> s >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i].first >> a[i].second;
    int len = max(0ll, a[0].first);
    for (int i = 1; i < n; ++ i) {
        len = max(len, a[i].first - a[i - 1].second);
        if (len >= s) {cout << "YES\n"; return;}
    }
    len = max(len, m - a[n - 1].second);
    cout << (len >= s ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}