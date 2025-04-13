#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 220;
constexpr int M = 1e4 + 10;
struct Edge {int to, nxt, w;}e[M << 1];
int n, m, k, s = 0, t = 201;
int head[N << 1], idx, x, y;
int lv[N << 1], cur[N << 1];
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
bool bfs() {
    fill(lv, lv + 2 + n, -1);
    memcpy(cur, head, sizeof(head));
    lv[0] = 0;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].w && lv[v] == -1) lv[v] = lv[u] + 1, q.push(v);
        }
    }
    return lv[n + 1] != -1;
}
int dfs(int u = 0, int flw = INF) {
    if (u == n + 1) return flw;
    int r = flw;
    for (int i = cur[u]; i && r; i = e[i].nxt) {
        cur[u] = i;
        int v = e[i].to;
        if (e[i].w && lv[v] == lv[u] + 1) {
            int c = dfs(v, min(e[i].w, r));
            r -= c;
            e[i].w -= c;
            e[i ^ 1].w += c;
        }
    }
    return flw - r;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i{}; i < k; ++ i) {
        int u, v; cin >> u >> v;
        u += 1, v += 101;
        addEdge(s, u, 1);
        addEdge(u, v, 1);
        addEdge(v, t, 1);

    }
    int ans{};
    while (bfs()) ans += dfs();
    cout << ans << "\n";
    return 0;
}