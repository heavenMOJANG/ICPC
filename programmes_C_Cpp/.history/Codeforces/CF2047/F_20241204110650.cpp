#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Edge {int to, nxt, vol;}e[2000];
int head[400], idx, vis[400], lv[400];
int S, T;
void addEdge(int u, int v, int vol) {
    e[idx] = {v, head[u], vol}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
void init() {
    fill(head, head + 400, -1);
    fill(vis, vis + 400, 0);
    fill(lv, lv + 400, -1);
    idx = 0;
}
bool bfs() {
    queue<int> q;
    q.push(S);
    vis[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (!vis[v] && e[i].vol) {
                q.push(v);
                vis[v] = 1;
                lv[v] = lv[u] + 1;
                if (v == T) return 1;
            }
        }
    }
    return lv[T] != -1;
}
void dfs(int )
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= m; ++ i) {
        int u, v; cin >> u >> v;
        addEdge(u, v, a[u]);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}