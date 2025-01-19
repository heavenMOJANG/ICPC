#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, m, k, idx, head[N], dis[N], vis[N];
struct Edge {int to, nxt, w;} e[N << 1];
struct Node {
    int id, d;
    bool operator < (const Node & x) const {return d > x.d;}
};
void init() {
    fill(dis, dis + 100010, 0);
    fill(head, head + 100010, 0);
    fill(e, e + 100010, 0);
    idx = 0;
    return;
}
void addEdge(int u, int v, int w) {
    e[++ idx] = (Edge){v, head[u], w};
    head[u] = idx;
    return;
}
void dijkstra() {
    priority_queue<Node> pq;
    dis[1] = 0;
    pq.push({1, dis[1]});
    while(!pq.empty()) {
        int u = pq.top().id; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].to) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                pq.push({v, dis[v]});
            }
        }
    }
    return;
}
void solve() {
    init();
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; ++ i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    for (int i = 2; i <= n; ++ i) dis[i] = k * (1 | i);
    dijkstra();
    for (int i = 2; i <= n; ++ i) cout << dis[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}