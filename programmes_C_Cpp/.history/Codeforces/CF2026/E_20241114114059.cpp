#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffffffffffff;
constexpr int N = 300;
constexpr int M = 1000;
int n, s, t, idx = 1, siz, maxn;
int head[N], cur[N], lv[N];
struct Edge {
    int to, nxt, vol;
}e[M];
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
void init() {
    cin >> n;
    idx = 1;
    siz = n + 61;
    s = ++ siz, t = ++ siz;
    fill(head, head + N, 0);
    for (int i = 0; i < 60; ++ i) addEdge(n + i + 1, t, 1);
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x;
        addEdge(s, i, 1);
        for (int j = 0; j < 60; ++ j) if (x >> j & 1ll) addEdge(i, n + j + 1, INF);

    }
}
bool bfs() {
    fill(lv + 1, lv + 1 + N, -1);
    lv[s] = 0;
    memcpy(cur, head, sizeof(head));
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].vol && lv[v] == -1) lv[v] = lv[u] + 1, q.push(v);
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
int dinic() {
    int res{};
    while (bfs()) res += dfs();
    return res;
}
void solve() {
    init();
    cout << n - dinic() << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}