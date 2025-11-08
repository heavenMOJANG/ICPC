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
    vector<int> w(n + 1), g[n + 1], dis(n + 1), tmp(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> w[i];
    for (int i = 1; i <= m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    priority_queue<Node> pq;
    pq.push({1, dis[1] = 0});
    tmp[1] = w[1];
    while (!pq.empty()) {
        auto [u, d] = pq.top(); pq.pop();
        if (d > dis[u]) continue;
        for (auto [v, c] : g[u]) {
            if (dis[v] > dis[u] + c || (dis[v] == dis[u] + c && tmp[v] < tmp[u] + w[v])) {
                dis[v] = dis[u] + c;
                tmp[v] = tmp[u] + w[v];
                pq.push({v, dis[v]});
            }
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}