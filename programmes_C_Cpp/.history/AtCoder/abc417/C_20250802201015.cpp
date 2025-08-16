#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    map<int, int> mp;
    for (int j = 1; j <= n; ++ j) mp[j - a[j]] ++;
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        int d = i - a[i];
        mp[d] --;
        int dd = i + a[i];
        if (mp.find(dd) != mp.end()) ans += mp.find(dd) -> second;
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}