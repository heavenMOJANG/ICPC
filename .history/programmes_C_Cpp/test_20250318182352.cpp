#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    int id, d;
    bool operator < (const Node & b) const { return d > b.d; }
};
vector<pair<int, int>> g[N];
int dis[N], vis[N], s;
void dijkstra(int s) {
    priority_queue<Node> pq;
    pq.push({s, dis[s] = 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}
void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dijkstra()
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}