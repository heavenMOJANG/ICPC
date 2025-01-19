#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Edge {int to, nxt, vol;}e[2000];
int head[400], idx, vis[400];
void addEdge(int u, int v, int vol) {
    e[idx] = {v, head[u], vol}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
void init() {
    fill(head, head + 400, -1);
    idx = 0;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= m; ++ i) {
        int u, v; cin >> u >> v;
        addEdge(u, v, a[u]);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}