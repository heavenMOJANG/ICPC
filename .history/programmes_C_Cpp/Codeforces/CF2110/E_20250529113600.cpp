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
    int rt{}, cnt{};
    for (int i{}; i < g.size(); ++ i) if (g[i].size() & 1) cnt ++, rt = i;
    vector<int> ans;
    function<void(int)> dfs = [&](int v) {
        while (!g[v].empty()) {
            int u = *g[v].begin();
            g[u].erase(v);
            g[v].erase(u);
            dfs(u);
        }
        ans.emplace_back(v);
    };
    dfs(rt);
    if (ans.size() != n + 1 || cnt > 2) { cout << "NO\n"; return; }
    vector<int> out;
    for (int i{}; i < n; ++ i) {
        auto p1 = e[ans[i]], p2 = e[ans[i + 1]];
        out.emplace_back(mp[{p1.first + p2.first, p1.second + p2.second}]);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}