#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
constexpr int M = 2e5 + 10;
struct Edge {int to, nxt, vol;}e[M];
int m, n, a[110][110], s, t;
int head[N], idx, lv[N], cur[N];
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
bool bfs() {
    queue<int> q;
    q.push(s);
    lv[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].vol &)
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
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j) cin >> a[i][j];
    
    return 0;
}