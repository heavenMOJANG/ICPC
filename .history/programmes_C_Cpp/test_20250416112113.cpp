#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int id, d, val;
    bool operator < (const Node& b) const { return d == b.d ? val > b.val : d > b.d; }
};
void solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<pair<int, int>> g[n + 1];
    for (int i{}; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> dis(n + 1, INF), hot(n + 1, INF);
    priority_queue<Node> pq; pq.push({s, dis[s] = 0, 0});
    while (!pq.empty()) {

    }
    if (dis[t] == INF) cout << "Impossible\n";
    else cout << dis[t] << " " << hot[t] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}