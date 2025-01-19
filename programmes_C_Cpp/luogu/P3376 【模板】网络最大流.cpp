#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e2 + 10;
constexpr int M = 5e3 + 10;
struct Edge {int to, nxt, vol;}e[M << 1];
int n, m, s, t, head[N << 1], idx = 1, lv[N << 1], cur[N << 1];
void addEdge(int u, int v, int w) {e[++ idx] = {v, head[u], w}, head[u] = idx;}
bool bfs() {
    fill(lv + 1, lv + 1 + n, -1);
    lv[s] = 0;
    memcpy(cur, head, sizeof(head));
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].vol && lv[v] == -1) lv[v] = lv[u] + 1, q.push(v);
        }
    }
    return lv[t] != -1;
}
int dfs(int u = s, int flw = INF) {
    if (u == t) return flw;
    int r = flw;
    for (int i = cur[u]; i && r; i = e[i].nxt) {
        cur[u] = i;
        int v = e[i].to;
        if (e[i].vol && lv[v] == lv[u] + 1) {
            int c = dfs(v, min(e[i].vol, r));
            r -= c;
            e[i].vol -= c;
            e[i ^ 1].vol += c;
        }
    }
    return flw - r;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, 0);
    }
    int ans{};
    while (bfs()) ans += dfs();
    cout << ans << "\n";
    return 0;
}