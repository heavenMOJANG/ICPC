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
void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], cap, cst}, head[u] = idx ++;
    e[idx] = {u, head[v], 0, -cst}, head[v] = idx ++;
}
bool spfa(int s, int t) {
    static int dis[N], pre[N], vis[N];
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s), dis[s] = 0, vis[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].cap && dis[v] > dis[u] + e[i].cst) {
                dis[v] = dis[u] + e[i].cst;
                pre[v] = i;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return dis[t] != 0x3f3f3f3f3f3f3f3f;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    int x, y, z;
    while (cin >> x >> y >> z && x && y && z) a[x][y] = z;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {

        }
    return 0;
}