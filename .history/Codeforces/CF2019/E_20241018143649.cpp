#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> maxDep(n + 1, 0), maxP(n + 1, 0), cntP(n + 1, 0), dep(n + 1, 0);
    int maxn{};
    function<void(int, int)> dfs = [&](int u, int f = 0) {
        dep[u] = dep[f] + 1;
        maxn = max(maxn, dep[u]);
        maxDep[u] = dep[u];
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(v, u);
            maxDep[u] = max(maxDep[u], maxDep[v]);
        }
        cntP[dep[u]] ++;
        maxP[maxDep[u]] ++;
    };
    dfs(1);

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}