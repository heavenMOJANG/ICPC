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
int dis[N], incf[N], pre[N], n, vis[N];
bool bfs(int s, int t) {
    fill(dis, dis + N, INF);
    fill(vis, vis + N, 0);
    fill(pre, pre + N, -1);
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
                pre[v] = i;
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
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    return 0;
}