#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v, p, q; cin >> u >> v >> p >> q;
        g[u].emplace_back(v, p);
        g[v].emplace_back(u, q);
    }
    vector<int> dep(n + 1, 0), siz(n + 1, 1), son(n + 1), top(n + 1), fa(n + 1);
    function<void(int, int)> dfs0 = [&](int u, int fa) {
        son[u] = -1;
        for (auto [v, w] : g[u]) {

        }
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}