#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 16e4 + 10;
constexpr int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
constexpr int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
struct Edge { int to, nxt, vol; }e[N << 2];
int n, s, t, ans;
int head[N], idx, lv[N], cur[N], vis[210][210];
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[u] = idx ++;
}
bool bfs() {
    fill(lv, lv + N, -1);
    queue<int> q; q.push(s);
    lv[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].vol && lv[v] == -1) lv[v] = lv[u] + 1, q.push(v);
        }
    }
    return lv[t] != -1;
}
int dfs(int u = s, int flow = INF) {
    if (u == t) return flow;
    int rest = flow;
    memcpy(cur, head, sizeof(head));
    for (int i = head[u]; ~i && rest; i = e[i].nxt) {
        cur[u] = i;
        int v = e[i].to;
        if (e[i].vol && lv[v] == lv[u] + 1) {
            int c = dfs(v, min(e[i].vol, rest));
            rest -= c;
            e[i].vol -= c;
            e[i ^ 1].vol += c;
        }
    }
    return flow - rest;
}
int dinic() {
    int res{};
    while (bfs()) res += dfs();
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int ans = n * n - m;
    for (int i = 1; i <= m; ++ i) {
        int x, y; cin >> x >> y;
        vis[x][y] = 1;
    }
    t = n * n + 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            if (vis[i][j]) continue;
            int p = (i - 1) * n + j;
            if ((i + j) & 1) addEdge(s, p, 1);
            else {
                addEdge(p, t, 1);
                for (int k = 0; k < 8; ++ k) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (tx < 1 || tx > n || ty < 1 || ty > n || vis[tx][ty]) continue;
                    addEdge((tx - 1) * n + ty, p, INF);
                }
            }
        }
    cout << ans - dinic() << "\n";
    return 0;
}