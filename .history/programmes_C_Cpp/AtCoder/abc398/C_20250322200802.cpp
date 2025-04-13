#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        mp[x].emplace_back(i + 1);
    }
    for (auto [x, y] : mp) {
        if (y.size() == 1) maxn = max(maxn, y[0]);
    }
    int maxn{};
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}