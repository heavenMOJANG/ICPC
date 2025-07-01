#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        mp[x] ++;
    }
    int ans{};
    for (auto it = mp.begin(); it != mp.end(); ++ it) {
        auto [x, y] = it;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}