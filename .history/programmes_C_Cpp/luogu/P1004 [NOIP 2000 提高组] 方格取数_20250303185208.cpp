#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 210;
struct Node { int to, nxt, cap, cst; }e[N << 2];
int n, head[N], idx, s, t, ret;
int a[10][10];
int cur[N], dis[N], inq[N];
void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], cap, cst}, head[u] = idx ++;
    e[idx] = {u, head[v], 0, -cst}, head[v] = idx ++;
}
bool spfa() {
    fill(dis, dis + N, INF);
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
    memcpy(cur, head, sizeof(head));
    inq[u] = 1;
    int used = 0;
    for (int i = cur[u]; ~i && used < flow; i = e[i].nxt) {
        int v = e[i].to;
        if (!inq[v] && e[i].cap && dis[v] == dis[u] + e[i].cst) {
            int c = dfs(v, min(flow - used, e[i].cap));
            if (c) ret += c * e[i].cst, e[i].cap -= c, e[i ^ 1].cap += c, used += c;
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
    fill(head, head + N, -1);
    cin >> n;
    int x, y, z;
    while (cin >> x >> y >> z && x && y && z) a[x][y] = z;
    s = 0, t = n * n * 2 + 1;
    addEdge(s, 1, 2, 0); addEdge(n * n + n * n, t, 2, 0);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            int p = (i - 1) * n + j;
            addEdge(p, p + n * n, 1, -a[i][j]);
            addEdge(p, p + n * n, INF, 0);
            if (j < n) addEdge(p + n * n, p + 1, INF, 0);
            if (i < n) addEdge(p + n * n, p + n, INF, 0);
        }
    cout << -ret << "\n";
    return 0;
}