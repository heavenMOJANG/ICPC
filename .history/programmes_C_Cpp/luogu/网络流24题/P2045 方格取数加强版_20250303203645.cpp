#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5010;
constexpr int M = 50010;
struct Edge { int to, nxt, cap, cst; } e[M];
int n, k, a[60][60];
int dis[N], cur[N], head[N], idx, s, t, ret;
void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], cap, cst}, head[u] = idx ++;
    e[idx] = {u, head[v], 0, -cst}, head[v] = idx ++;
}
int in(int x, int y) { return (x - 1) * n + y; }
int out(int x, int y) { return in(x, y) + n * n; }
bool spfa() {

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) cin >> a[i][j];
    s = 0, t = n * n * 2 + 1;
    addEdge(s, 1, k, 0);
    addEdge(n * n * 2, t, k, 0);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            int p = (i - 1) * n + j;
            addEdge(in(i, j), out(i, j), 1, -a[i][j]);
            if (j < n) addEdge(out(i, j), in(i, j + 1), INF, 0);
            if (i < n) addEdge(out(i, j), in(i + 1, j), INF, 0);
        }
    return 0;
}