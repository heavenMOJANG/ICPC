#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 1e15;
constexpr int N = 2e5 + 10;
constexpr int M = 2e5 + 10;
struct Edge { int to, nxt, cst; } e[N + M << 1];
struct Node {
    int id, d;
    bool operator < (const Node &rhs) const { return d > rhs.d; }
};
int n, m, x, head[N << 1], dis[N << 1], idx, vis[N << 1];
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
}
void solve() {
    fill(head, head + 2 * N, -1);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; ++ i) addEdge(i, i + n, x), addEdge(i + n, i, x);
    for (int i = 0; i < m; ++ i) {
        int u, v; cin >> u >> v;
        addEdge(u, v, 1), addEdge(v + n, u + n, 1);
    }
    priority_queue<Node> pq;
    fill(dis, dis + 2 * N, INF);
    pq.emplace(1, dis[1] = 0);
    while (!empty(pq)) {
        auto [u, d] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].cst) dis[v] = dis[u] + e[i].cst;
            pq.emplace(v, dis[v]);
        }
    }
    cout << min(dis[n], dis[2 * n]) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}