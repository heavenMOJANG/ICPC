#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    set<int> s;
    for (int i = 0, x; i < n; ++ i) cin >> x, mp[x] ++, s.insert(x);
    int ans{}, sum{};
    for (auto it = s.begin(); it != s.end(); ++ it) {
        while (mp.count(*it) && mp.count(k - *it)) {
            ans ++;
            mp[*it] = max(0ll, mp[*it] - 1);
            mp[k - *it] = max(0ll, mp[k - *it] - 1);
        }
        sum += mp[*it];
    }
    if (sum & 1) cout << "0\n";
    else cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}