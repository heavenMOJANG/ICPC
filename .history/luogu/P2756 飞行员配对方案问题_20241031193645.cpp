#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 110;
struct Edge {int to, nxt, w;}e[N << 4];
int n, m, head[N], idx, u, v;
void addEdge(int u, int v, int w) {e[idx] = {v, head[u], w}, head[u] = idx ++;}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> m >> n;
    while (cin >> u >> v && ~u && ~v) {
        addEdge(u, v, 1);
        addEdge(v, u, 0);
    }
    for (int i = 1; i <= m; ++ i) {
        addEdge(0, i, 1);
        addEdge(i, 0, 0);
    }
    for (int i = n - m + 1; i <= n; ++ i) {
        addEdge(i, n + 1, 1);
        addEdge(n + 1, i, 0);
    }
    return 0;
}