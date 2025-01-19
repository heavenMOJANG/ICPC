#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
constexpr int M = 1e6 + 10;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
struct Edge {int to, nxt, w, cst;}e[M];
int head[N], idx;
void addEdge(int u, int v, int w, int c) {
    e[idx] = {v, head[u], w, c}, head[u] = idx ++;
    e[idx] = {u, head[v], 0, -c}, head[v] = idx ++;
}
int n, k, a, b, c;
int dis[N], incf[N], lv[N], vis[N];
bool bfs(int s, int t) {
    fill(dis, dis + N, INF);
    fill(vis, vis + N, 0);
    fill(lv, lv + N, -1);
    queue<int> q; q.push(s);
    vis[s] = 1;
    incf[s] = INF;
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w, c = e[i].cst;
            if (!w) continue;
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                lv[v] = i;
                incf[v] = min(incf[u], w);
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return lv[t] != -1;
}
int dfs(int s, int t) {
    int x = t;
    while (x != s) {
        int i = lv[x];
        e[i].w -= incf[t];
        e[i ^ 1].w += incf[t];
        x = e[i ^ 1].to;
    }
    return dis[t] * incf[t];
}
int dinic(int s, int t) {
    int ans{};
    while (bfs(s, t)) ans += dfs(s, t);
    return ans;
}
int getId(int x, int y, int k) {return (x - 1) * n + y + k * n * n;}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fill(head, head + N, -1);
    cin >> n >> k >> a >> b >> c;
    addEdge(0, getId(1, 1, k), 1, 0);
    for (int i = 0; i <= k; ++ i) addEdge(getId(n, n, i), n + 1, INF, 0);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            int val; cin >> val;
            if (val) {
                for (int t = 0; t < k; ++ t) addEdge(getId(i, j, t), getId(i, j, k), INF, a);
                for (int t = 0; t < 4; ++ t) {
                    int ti = i + dx[t], tj = j + dy[t];
                    if (ti <= 0 || tj <= 0 || ti > n || tj > n) continue;
                    int len = 0;
                    if (ti < i || tj < j) len = b;
                    addEdge(getId(i, j, k), getId(ti, tj, k - 1), INF, len);
                }
            } else {
                for (int t = 0; t < 4; ++ t) {
                    int ti = i + dx[t], tj = j + dy[t];
                    if (ti <= 0 || tj <= 0 || ti > n || tj > n) continue;
                    int len = 0;
                    if (ti < i || tj < j) len = b;
                    for (int l = 1; l <= k; ++ l) addEdge(getId(i, j, l), getId(ti, tj, l - 1), INF, len);
                }
                addEdge(getId(i, j, 0), getId(i, j, k), INF, a + c);
            }
        }
    cout << dinic(0, n + 1) << "\n";
    return 0;
}