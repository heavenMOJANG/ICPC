#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<int, int> p, v;
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; ++ i) {
        int u, v; cin >> u >> v;
        mp[{u, v}] = i;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}