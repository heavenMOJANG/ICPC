#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(n + 1), dis(n * 2 + 10, INF);
    vector<pair<int, int>> g[n * 2 + 10];
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(u + n, 0);
        g[]
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}