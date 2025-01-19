#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    map<string, set<int>>
    for (int i = 1; i <= n; ++ i) {
        string s; cin >> s;
        mp[s[0]].emplace_back(i);
        mp[s[1]].emplace_back(i);
    }
    for (auto & [ch, v] : mp) sort(v.begin(), v.end());
    while (q --) {
        int u, v; cin >> u >> v;

    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}