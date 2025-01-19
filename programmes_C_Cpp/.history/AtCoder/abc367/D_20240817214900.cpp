#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), pre(2 * n + 1);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    pre[0] = 0;
    for (int i = 0; i < 2 * n; ++ i) pre[i + 1] = (pre[i] + a[i % n]) % m;
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) mp[pre[i]] ++;
    int ans = 0;
    for (int i = n; i < 2 * n; ++ i) {
        mp[pre[i - n]] ++;
        ans += mp[pre[i]];
        mp[pre[i]] ++;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}