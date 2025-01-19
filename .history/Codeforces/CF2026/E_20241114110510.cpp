#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 1e18;
constexpr int N = 1e5 + 10;
constexpr int M = 2e6 + 10;
int n, S, T, idx = 1, siz, maxn;
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
    maxn = n + 100;
    S = ++ siz, T = ++ siz;
    fill(head, head + maxn, 0);
    for (int i = 0; i <= 60; ++ i) addEdge(n + i + 1, T, 1);
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x;
        addEdge(S, i, 1);
        for (int j = 0; j < 60; ++ j) if (x >> j & 1ll) addEdge(i, n + j + 1, INF);

    }
}
bool bfs() {
    fill(lv, lv + siz + 1, 0);
    memcpy(cur, head, (siz + 1) * sizeof(int));
    queue<int> q;
    q.push(S);
    lv[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].vol && !lv[v]) {
                lv[v] = lv[u] + 1;
                q.push(v);
            }
        }  
    }
    return lv[T];
}
int dfs(int u = S, int flow = INF) {
    if (u == T) return flow;
    int res{};
    for (int i = cur[u]; i && flow; i = e[i].nxt) {
        int v = e[i].to;
        if (e[i].vol && lv[v] == lv[u] + 1) {
            int c = dfs(v, min(flow, e[i].vol));
            if (!c) lv[v] = 0;
            flow -= c;
            res += c;
            e[i].vol -= c;
            e[i ^ 1].vol += c;
            if (!flow) return res;
        }
    }
    if (!res) lv[u] -= 2;
    return res;
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