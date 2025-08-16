#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 2e15;
constexpr int N = 510;
int dis[510][510];
void solve() {
    int n, m; cin >> n >> m;
    for (int i{}; i <= n; ++ i)
        for (int j{}; j <= n; ++ j) dis[i][j] = i == j ? 0ll : INF;
    for (int i{}; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min({dis[u][v], dis[v][u], w});
    }
    for (int k = 1; k <= n; ++ k)
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int k, t; cin >> k >> t;
    vector<int> ports;
    auto addEdge = [&](int u, int v, int w) {
        if (dis[u][v] > w) dis[u][v] = dis[v][u] = w;
        for (int i{}; i <= n; ++ i) {
            int du = dis[i][u], dv = dis[i][v];
            if (du == INF && dv == INF) continue;
            for (int j{}; j <= n; ++ j) {
                int p1 = du < INF && dis[v][j] < INF ? du + w + dis[v][j] : INF;
                int p2 = dv < INF && dis[u][j] < INF ? dv + w + dis[u][j] : INF;
                dis[i][j] = min({dis[i][j], p1, p2});
            }
        }
    };
    for (int i{}; i < k; ++ i) {
        int x; cin >> x;
        for (auto y : ports) addEdge(x, y, t);
        ports.emplace_back(x);
    }
    for (int i = 1; i <= n; ++ i) if (dis[0][i] < INF) addEdge(0, i, dis[0][i]);
    int q; cin >> q;
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int u, v, w; cin >> u >> v >> w;
            addEdge(u, v, w);
        }
        if (op == 2) {
            int x; cin >> x;
            addEdge(0, x, t);
        }
        if (op == 3) {
            int ans{};
            for (int i = 1; i <= n; ++ i)
                for (int j = 1; j <= n; ++ j) if (dis[i][j] < INF) ans += dis[i][j];
            cout << ans << "\n";
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