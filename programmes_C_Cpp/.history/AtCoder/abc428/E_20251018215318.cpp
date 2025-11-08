#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i{}, u, v; i < n - 1; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto bfs = [&](int s) {
        vector<int> dist(n + 1, -1);
        queue<int> q; q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u])
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
        }
        int p = s;
        for (int i = 1; i <= n; ++ i) if (dist[i] > dist[p] || (dist[i] == dist[p] && i > p)) p = i;
        return make_pair(p, dist);
    };
    auto [u, disu] = bfs(1);
    auto [v, disv] = bfs(u);
    for (int i = 1; i <= n; ++ i)
        if (disu[i] > disv[i] || (disu[i] == disv[i] && u > v)) cout << u << "\n";
        else cout << v << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}