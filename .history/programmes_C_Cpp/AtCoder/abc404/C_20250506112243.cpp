#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;

void solve() {
    int n, m; cin >> n >> m;
    int ok = 1;
    vector<int> g[n + 1], vis(n + 1, 0);
    function<void(int, int, int)> dfs = [&](int u, int fa, int lv) {
        if (vis[u]) {
            if (lv != n) return;
            return;
        }
        vis[u] = 1;
        if (g[u].size() != 2) return;
        for (auto v : g[u]) {

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