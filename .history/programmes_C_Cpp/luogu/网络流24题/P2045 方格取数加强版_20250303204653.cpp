#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5010;
constexpr int M = 50010;
struct Edge { int to, nxt, cap, cst; } e[M];
int n, k, a[60][60];
int dis[N], cur[N], head[N], idx, s, t, ret, inq[N];
void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], cap, cst}, head[u] = idx ++;
    e[idx] = {u, head[v], 0, -cst}, head[v] = idx ++;
}
int in(int x, int y) { return (x - 1) * n + y; }
int out(int x, int y) { return in(x, y) + n * n; }
bool spfa() {
    fill(dis, dis + N, INF);
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    q.push(s), dis[s] = 0, inq[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].cap && dis[v] > dis[u] + e[i].cst) {
                dis[v] = dis[u] + e[i].cst;
                if (!inq[v]) q.push(v), inq[v] = 1;
            }
        }
    }
    return dis[t] != INF;
}
int dfs(int u = s, int flow = INF) {
    if (u == t) return flow;
    inq[u] = 1;
    int used = 0;
    for (int &i = cur[u]; ~i && used < flow; i = e[i].nxt) {
        int v = e[i].to;
        if (!inq[v] && e[i].cap && dis[v] == dis[u] + e[i].cst) {
            int c = dfs(v, min(flow - used, e[i].cap));
            ret += c * e[i].cst;
            e[i].cap -= c;
            e[i ^ 1].cap += c;
            used += c;
        }
    }
    inq[u] = 0;
    return used;
}
int mcmf() {
    int res{};
    while (spfa()) {
        int x;
        while (x = dfs()) res += x;
    }
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) cin >> a[i][j];
    s = 0, t = n * n * 2 + 1;
    addEdge(s, in(1, 1), k, 0);
    addEdge(out(n, n), t, k, 0);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            addEdge(in(i, j), out(i, j), 1, -a[i][j]);
            addEdge(in(i, j), out(i, j), INF, 0);
            if (j < n) addEdge(out(i, j), in(i, j + 1), INF, 0);
            if (i < n) addEdge(out(i, j), in(i + 1, j), INF, 0);
        }
    mcmf();
    cout << -ret << "\n";
    return 0;
}