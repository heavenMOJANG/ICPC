#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int id, d;
    bool operator < (const Node &b) const { return d > b.d; }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(n + 1), dis(n * 2 + 10, INF), dis(2 * n + 10, 0);
    vector<pair<int, int>> g[n * 2 + 10];
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(u + n, w[u]);
        g[u + n].emplace_back(u, w[u]);
        g[v].emplace_back(v + n, w[v]);
        g[v + n].emplace_back(v, w[v]);
        g[u + n].emplace_back(v, 0);
        g[v].emplace_back(u + n, 0);
        g[v + n].emplace_back(u, 0);
        g[u].emplace_back(v + n, 0);
    }
    fill(dis.begin(), dis.end(), INF);
    priority_queue<Node> pq;
    pq.push({1, dis[1] = 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top(); pq.pop();
        if (vis[u]) continue;
        
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}