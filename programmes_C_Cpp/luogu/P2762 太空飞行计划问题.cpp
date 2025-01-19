#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 510;
struct Edge {int to, nxt, w;}e[N * N];
int m, n, head[N], idx;
int lv[N], s, t;
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
bool bfs() {
    queue<int> q;
    fill(lv, lv + N, -1);
    lv[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (lv[v] == -1 && e[i].w) {
                lv[v] = lv[u] + 1;
                q.push(v);
            }
        }
    }
    return lv[t] != -1;
}
int dfs(int u = s, int flow = INF) {
    int r{};
    if (u == t) return flow;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (e[i].w && lv[v] == lv[u] + 1) {
            int c = min(e[i].w, flow - r);
            c = dfs(v, c);
            r += c;
            e[i].w -= c;
            e[i ^ 1].w += c;
        }
    }
    if (!flow) lv[u] -= 2;
    return r;
}
int dinic() {
    int ans{};
    while (bfs()) ans += dfs();
    return ans;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> m >> n;
    s = 200, t = 201;
    for (int i = 1; i <= m; ++ i) {
        
    }
    return 0;
}