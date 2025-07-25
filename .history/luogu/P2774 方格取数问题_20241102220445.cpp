#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e4 + 10;
struct Edge {int to, nxt, vol;}e[N << 2];
int m, n, a[N], s, t, ans;
int head[N], idx, lv[N], cur[N];
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
bool bfs() {
    fill(lv, lv + N, -1);
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    q.push(s);
    lv[s] = 0;
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
int dinic() {
    int res{};
    while (bfs()) res += dfs();
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> m >> n;
    t = m * n + 1;
    for (int i = 1; i <= m * n; ++ i) cin >> a[i], ans += a[i];
    for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j) {
            int p = (i - 1) * n + j;
            if ((i + j) & 1) addEdge(p, t, a[p]);
            else {
                addEdge(s, p, a[p]);
                if (i > 1) addEdge(p, p - n, INF);
                if (i < m) addEdge(p, p + n, INF);
                if (j > 1) addEdge(p, p - 1, INF);
                if (j < n) addEdge(p, p + 1, INF);
            }
        }
    cout << ans - dinic() << "\n";
    return 0;
}