#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    map<int, int> mp;
    int ans{}, pre{}, lst = -1;
    mp[0] = -1;
    for (int i = 0; i < n; ++ i) {
        pre += a[i];
        if (mp.find(pre) != mp.end()) {
            int p = mp[pre];
            if (p >= lst) {
                ans ++;
                lst = i;
            }
        }
        mp[pre] = i;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}