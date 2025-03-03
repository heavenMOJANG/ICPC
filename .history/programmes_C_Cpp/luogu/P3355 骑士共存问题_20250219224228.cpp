#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
constexpr int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
constexpr int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
struct Edge { int to, nxt, vol; }e[N << 1];
int n, m, s, t, ans;
int head[N], idx, lv[N], cur[N], vis[210][210];
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
bool bfs() {
    fill(lv, lv + n * n + 1, -1);
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
int dfs(int u = s, int flw = INF) {
    if (u == t) return flw;
    int r = flw;
    memcpy(cur, head, sizeof(int) * idx);
    for (int i = cur[u]; ~i && r; i = e[i].nxt) {
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
    fill(head, head + N, -1);
    cin >> n >> m;
    int ans = n * n - m;
    for (int i = 1; i <= m; ++ i) {
        int x, y; cin >> x >> y;
        vis[x][y] = 1;
    }
    s = 0, t = n * n + 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            if (vis[i][j]) continue;
            int p = (i - 1) * n + j;
            if ((i + j) & 1) addEdge(p, t, 1);
            else {
                addEdge(s, p, 1);
                for (int k = 0; k < 8; ++ k) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (tx < 1 || tx > n || ty < 1 || ty > n || vis[tx][ty]) continue;
                    int q = (tx - 1) * n + ty;
                    addEdge(p, q, INF);
                }
            }
        }
    cout << ans - dinic() << "\n";
    return 0;
}