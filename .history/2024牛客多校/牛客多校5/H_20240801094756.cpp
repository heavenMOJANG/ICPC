#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n], h(n, 0);
    vector<vector<int>> dep(n + 1, vector<int>(n + 1, 0));
    for (int i = 0, u, v; i < m; ++ i) {
        cin >> u >> v;
        u --, v --;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        h[u] |= 1ll << u;
        h[v] |= 1ll << v;
    }
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int u, const int & f, int len = 1) {
    };
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}