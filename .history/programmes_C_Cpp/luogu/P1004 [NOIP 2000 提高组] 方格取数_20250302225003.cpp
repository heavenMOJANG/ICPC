#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 210;
struct Node { int to, nxt, cap, cst; }e[N];
int n, head[N], idx, s, t;
int a[10][10];
int cur[N], dis[N], vis[N];
void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], cap, cst}, head[u] = idx ++;
    e[idx] = {u, head[v], 0, -cst}, head[v] = idx ++;
}
bool spfa(int s, int t) {
    fill(dis, dis + N, INF);
    memcpy(cur, head, sizeof head);
    queue<int> q;
    q.push(s), dis[s] = 0, vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].cap && dis[v] > dis[u] + e[i].cst) {
                dis[v] = dis[u] + e[i].cst;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return dis[t] != INF;
}
int dfs(int u, int t, int flow = INF) {
    if (u == t) return flow;
    vis[u] = 1;
    int used = 0;
    for (int &i = cur[u]; ~i && used < flow; i = e[i].nxt) {
        int v = e[i].to;
        if (!vis[v] && e[i].cap && dis[v] == dis[u] + e[i].cst) {
            int w = dfs(v, t, min(flow - used, e[i].cap));
            if (w) e[i].cap -= w, e[i ^ 1].cap += w, used += w;
        }
    }
    vis[u] = 0;
    return used;
}
int mcmf() {
    int res{};
    while (spfa(s, t)) {
        int x;
        while (x = dfs(s, t)) res += x;
    }
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    int x, y, z;
    while (cin >> x >> y >> z && x && y && z) a[x][y] = z;
    s = 0, t = n * n + 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {

        }
    return 0;
}