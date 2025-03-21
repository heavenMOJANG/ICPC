#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> g[n * k + 1], siz(n * k + 1, 1);
    for (int i = 1; i < n * k; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    function<void(int, int, int)> dfs = [&](int u, int f, int k) {
        if (!k) {
            dfs(u, f, 1);
            for (auto v : g[u]) if (v != f) dfs(v, u, 0);
        } else {

        }
    };
    dfs(1, -1, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}