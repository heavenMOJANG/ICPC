#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> g[n + 1];
    for (int i = 1, u, v, w; i < n; ++ i) {
        cin >> u >> v >> w;
        g[u].emplace_back(make_pair(v, w));
        g[v].emplace_back(make_pair(u, w));
    }
    function<void(int, int)> dfs = [&](int u, int f) {

    };
    dfs(1, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}