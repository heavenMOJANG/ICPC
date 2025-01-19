#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, m, k, idx, head[N], dis[N], vis[N], f[N];
struct Edge {int to, nxt, w;} e[N << 1];
struct Node {
    int id, d;
    bool operator < (const Node & x) const {return d > x.d;}
};
priority_queue<Node> pq;
void init() {
    fill(dis, dis + N, LLONG_MAX);
    fill(head, head + N, 0);
    memset(e, 0, sizeof(e));
    fill(f, f + N, -1);
    while(!pq.empty()) pq.pop();
    idx = 0;
    return;
}
void addEdge(int u, int v, int w) {
    e[++ idx] = {v, head[u], w};
    head[u] = idx;
    return;
}
void dijkstra() {
    
    return;
}
int dfs(int x) {
    if (f[x] != -1) return f[x];
    if (x == x & (-x)) return f[x] = dis[x];
    int minn = LLONG_MAX;
    for (int i = 0; i < 17; ++ i)
        if ((x >> i) & 1 == 1) minn = min(minn, dfs(x & ~(1ll << i)));
    return f[x] = minn;
}
void solve() {
    init();
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; ++ i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    dis[1] = 0;
    pq.push({1, dis[1]});
    while(!pq.empty()) {
        int u = pq.top().id; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        cout << u << "\n";
        for (int i = head[u]; i; i = e[i].to) {
            int v = e[i].to;
            if (!vis[v] && dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                pq.push({v, dis[v]});
            }
        }
    }
    for (int i = 1; i <= n; ++ i) dfs(i);
    vis[1] = 0;
    while(!pq.empty()) pq.pop();
    pq.push({1, dis[1] = 0});
    for (int i = 2; i <= n; ++ i) {
        vis[i] = 0;
        if (f[i] != LLONG_MAX) dis[i] = min(f[i] + k * i, k * (1 | i));
        else dis[i] = k * (1 | i);
        pq.push({i, dis[i]});
    }
    while(!pq.empty()) {
        int u = pq.top().id; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        cout << u << "\n";
        for (int i = head[u]; i; i = e[i].to) {
            int v = e[i].to;
            if (!vis[v] && dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                pq.push({v, dis[v]});
            }
        }
    }
    for (int i = 2; i <= n; ++ i) cout << dis[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}