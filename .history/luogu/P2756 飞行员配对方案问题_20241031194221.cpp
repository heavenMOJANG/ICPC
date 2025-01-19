#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 110;
struct Edge {int to, nxt, w;}e[N << 4];
int n, m, head[N << 1], idx, u, v, lv[N << 1], cur[N << 1];
void addEdge(int u, int v, int w) {e[idx] = {v, head[u], w}, head[u] = idx ++;}
bool bfs() {
    fill(lv + 1, lv + 1 + n, -1);
    memcpy(cur, head, sizeof(head));
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
int dfs(int u = 0, int flw = INF)
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> m >> n;
    while (cin >> u >> v && ~u && ~v) {
        addEdge(u, v, 1);
        addEdge(v, u, 0);
    }
    for (int i = 1; i <= m; ++ i) {
        addEdge(0, i, 1);
        addEdge(i, 0, 0);
    }
    for (int i = n - m + 1; i <= n; ++ i) {
        addEdge(i, n + 1, 1);
        addEdge(n + 1, i, 0);
    }
    return 0;
}