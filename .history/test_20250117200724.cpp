#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
struct Edge {
    int to, nxt, w;
}e[N];
struct Node {
    int id, d;
    bool operator < (const Node & b) const {return d > b.d;}
};
int idx, head[N] = {-1}, vis[N], dis[N] = {INF}, S, T;
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
}
void dijkstra() {
    priority_queue<Node> pq;
    pq.push({0, dis[0] = 0});
    while (!pq.empty()) {
        int u = pq.top().id; pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (!vis[v] && dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                pq.push({v, dis[v]});
            }
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int t{};
    for (int i = 0; i < n; ++ i)  cin >> a[i], t = max(t, a[i] + m - 1);
    vector<int> b(n), val(n);
    for (int i = 0; i < n; ++ i) cin >> b[i] >> val[i];
    T = t + 1;
    fill(head, head + N, -1);
    fill(dis, dis + N, INF);
    for (int i = 0; i < t; ++ i) addEdge(i, i + 1, 0);
    for (int i = 0; i < n; ++ i) addEdge(a[i] - 1, a[i] + m - 1, b[i]), addEdge(a[i] + m - 1, T, val[i]);
    dijkstra();
    cout << dis[T] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}