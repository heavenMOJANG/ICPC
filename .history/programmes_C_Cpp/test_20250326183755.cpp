#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1], dep(n + 1, 0);
    int rt{};
    for (int i = 1; i <= n; ++ i) {
        int fa; cin >> fa;
        if (fa == -1) rt = i;
        else g[fa].emplace_back(i);
    }
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (int v : g[u]) dfs(v, d + 1);
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}