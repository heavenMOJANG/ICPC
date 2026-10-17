#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
struct Edge { int to, w; };
void solve() {
    int N, M, Y; cin >> N >> M >> Y;
    vector<vector<Edge>> G(N + 1);
    for (int i{}; i < M; ++ i) {
        int u, v, T; cin >> u >> v >> T;
        G[u].emplace_back(v, T);
        G[v].emplace_back(u, T);
    }
    for (int i{1}; i <= N; ++ i) {
        int X; cin >> X;
        G[i].emplace_back(0ll, X + Y);
        G[0].emplace_back(i, X);
    }
    vector<int> dis(N + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dis[1] = 0;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dis[u]) continue;
        for (const auto& [v, w] : G[u])
            if (dis[u] + w < dis[v]) dis[v] = dis[u] + w, pq.emplace(dis[v], v);
        for (int i{2}; i <= N; ++ i) cout << dis[i] << " \n"[i == N];
    }
    //especially normal in the GPLT L3-1
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}