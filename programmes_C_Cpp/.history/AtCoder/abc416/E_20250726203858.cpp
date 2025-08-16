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
    for (int i{}; i < k; ++ i) {
        int x; cin >> x;
        dis[0][x] = dis[x][0] = min({dis[0][x], dis[x][0], t});
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}