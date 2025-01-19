#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 1e18;
constexpr int N = 2e5 + 10;
struct Node {
    int dis, id, flag;
    bool operator < (const Node & x) const {return x.dis < dis;}
};
void solve() {
    int n, m, h; cin >> n >> m >> h;
    vector<int> diss(n + 1), dist(n + 1), sp(n + 1);
    for (int i = 0; i <= n; ++ i) sp[i] = 0;
    for (int i = 1, x; i <= h; ++ i) {
        cin >> x;
        sp[x] = 1;
    }
    vector<pii> g[n + 1];
    for (int i = 1, u, v, w; i <= m; ++ i) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    auto dijkstraOne = [&](int s) {
        vector<vector<int>> res(2, vector<int>(n + 1, INF)), vis(2, vector<int>(n + 1, 0));
        priority_queue<Node> pq;
        pq.push({0, s, sp[s]});
        res[0][s] = 0;
        while (!pq.empty()) {
            auto [dis, u, flag] = pq.top(); pq.pop();
            if (vis[flag][u]) continue;
            vis[flag][u] = 1;
            for (auto [v, w] : g[u]) {
                if (flag) w /= 2;
                if (res[0][v] > dis + w) {
                    res[0][v] = dis + w;
                    pq.push({res[0][v], v, flag | sp[v]});
                }
                if (flag && res[1][v] > dis + w) {
                    res[1][v] = dis + w;
                    pq.push({res[1][v], v, flag | sp[v]});
                }
            }
        }
        for (int i = 1; i <= n; ++ i) diss[i] = min(res[0][i] ,res[1][i]);
    };
    auto dijkstraTwo = [&](int s) {
        vector<vector<int>> res(2, vector<int>(n + 1, INF)), vis(2, vector<int>(n + 1, 0));
        priority_queue<Node> pq;
        pq.push({0, s, sp[s]});
        res[0][s] = 0;
        while (!pq.empty()) {
            auto [dis, u, flag] = pq.top(); pq.pop();
            if (vis[flag][u]) continue;
            vis[flag][u] = 1;
            for (auto [v, w] : g[u]) {
                if (flag) w /= 2;
                if (res[0][v] > dis + w) {
                    res[0][v] = dis + w;
                    pq.push({res[0][v], v, flag | sp[v]});
                }
                if (flag && res[1][v] > dis + w) {
                    res[1][v] = dis + w;
                    pq.push({res[1][v], v, flag | sp[v]});
                }
            }
        }
        for (int i = 1; i <= n; ++ i) dist[i] = min(res[0][i] ,res[1][i]);
    };
    dijkstraOne(1);
    dijkstraTwo(n);
    int ans = INF;
    for (int i = 1; i <= n; ++ i) ans = min(ans, max(diss[i], dist[i]));
    cout << (ans == INF ? -1ll : ans) << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}