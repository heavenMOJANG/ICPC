#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int to(int x, int s) {
    return x * 1024 + s;
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i{}; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
    }
    vector dis(1025, vector<int> (1024, -1));
    queue<pair<int, int>> q;
    q.push({1, 0}); dis[1][0] = 0;
    while (!q.empty()) {
        auto [u, s] = q.front(); q.pop();
        if (dis[x][s] != -1) continue;
        for (auto [v, t] : g[{x, s}]) {
            if (dis[v][t] == -1) {
                dis[v][t] = dis[x][s] + 1;
                q.push({v, t});
            }
        }
    }
    int ans = INF;
    for (int i{}; i < 1024; ++ i) if (dis[n][i] != -1) ans = min(ans, dis[n][i]);
    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}