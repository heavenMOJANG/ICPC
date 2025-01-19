#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(2 * n + 2, 0);
    map<int, int> mp;
    mp[0] = 1;
    int ans = 0, pre = 0;
    for (int i = 1, x; i <= n; ++ i) {
        cin >> a[i];
        pre += x;
        ans += mp[pre % m];
        mp[pre % m] ++;
    }
    for (int i = n + 1; i < 2 * n; ++ i) {
        a[i] = a[i - n];
        pre += a[i];
        ans += mp[pre % m];
        mp[pre % m] ++;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}