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
    vector<set<int>> g;
    for (int i = 1; i <= n; ++ i) {
        int a, b; cin >> a >> b;
        mp[{a, b}] = i;
        if (!p.count(b)) {
            p[b] = g.size();
            g.emplace_back(set<int>());
            e.emplace_back(0, b);
        }
        if (!v.count(a)) {
            v[a] = g.size();
            g.emplace_back(set<int>());
            e.emplace_back((a, 0));
        }
        g[v[a]].insert(p[b]);
        g[p[b]].insert(v[a]);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}