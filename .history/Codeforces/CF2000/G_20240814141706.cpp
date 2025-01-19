#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {int v, w1, w2;};
void solve() {
    int n, m, t0, t1, t2; cin >> n >> m >> t0 >> t1 >> t2;
    vector<Node> g[n + 1];
    for (int i = 0; i < m; ++ i) {
        int u, v, w1, w2; cin >> u >> v >> w1 >> w2;
        g[u].emplace_back(v, w1, w2);
        g[v].emplace_back(u, w1, w2);
    }
    auto check = [&](int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n + 1, 0), dis(n + 1, INF);
        dis[1] = x;
        pq.push({dis[1], 1});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w1, w2] : g[u]) {
                dis[v] = min(dis[v], dis[u] + w2);
                if (dis[u] + w1 <= t1 || dis[u] >= t2) dis[v] = min(dis[v], dis[u] + w1);
                else dis[v] = min(dis[v], t2 + w1);
                pq.push({dis[v], v});
            }
        }
        return dis[n] <= t0;
    };
    int l = -1, r = t0;
    while (l < r) {
        int mid = l + r + 1 >> 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}