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
    fill(dis, 64, sizeof(dis));
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    return 0;
}