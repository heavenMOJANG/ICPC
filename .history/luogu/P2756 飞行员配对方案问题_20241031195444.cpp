#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 110;
constexpr int M = 1e4 + 10;
struct Edge {int to, nxt, w;}e[M << 1];
int n, m, head[N << 1], idx, x, y, lv[N << 1], cur[N << 1];
void addEdge(int u, int v, int w) {e[idx] = {v, head[u], w}, head[u] = idx ++;}
bool bfs() {
    fill(lv, lv + N, -1);
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
    cin >> m >> n;
    while (cin >> x >> y && ~x && ~y) {
        addEdge(x, y, 1);
        addEdge(y, x, 0);
    }
    for (int i = 1; i <= m; ++ i) {
        addEdge(0, i, 1);
        addEdge(i, 0, 0);
    }
    for (int i = n - m + 1; i <= n; ++ i) {
        addEdge(i, n + 1, 1);
        addEdge(n + 1, i, 0);
    }
    int ans{};
    while (bfs()) ans += dfs();
    cout << ans << "\n";
    for (int i = 0; i < idx; i += 2)
        if (e[i].to > m && e[i].to <= n && !e[i].w) cout << e[i ^ 1].to << " " << e[i].to << "\n";
    return 0;
}