#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> g[n + 1];
    for (int i{}; i < n - 1; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> dis(n + 1, -1);
    queue<int> q; q.push(1); dis[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u])
            if (dis[v] == -1) dis[v] = dis[u] + 1, q.push(v);
    }
    for (int i = 2; i <= n; ++ i) cout << (dis[i] % k == 0 ? dis[i] / k : -1ll) << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}