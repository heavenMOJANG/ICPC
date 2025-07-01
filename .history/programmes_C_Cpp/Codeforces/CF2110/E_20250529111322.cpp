#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> e;
    map<int, int> mp;
    int cur{};
    vector<int> g[n];
    for (int i{}; i < n; ++ i) {
        cin >> e[i].first >> e[i].second;
        if (mp.count(e[i].first)) e[i].first = mp[e[i].first]; else 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}