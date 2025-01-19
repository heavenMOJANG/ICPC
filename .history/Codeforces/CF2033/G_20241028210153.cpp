#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Query {
    int k, id;
    Query (int _k, int _id) : k(_k), id(_id) {}
};
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> dep(n + 1, 0), maxDep(n + 1, 0);
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        maxDep[u] = 0;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs1(v, u);
            maxDep[u] = max(maxDep[u], maxDep[v] + 1);
        }
    };
    dfs1(1, 0);
    int m; cin >> m;
    vector<vector<Query>> querys(n + 1);
    vector<int> ans(m);
    for (int i = 0; i < m; ++ i) {
        int v, k; cin >> v >> k;
        querys[i].emplace_back(k, i);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}