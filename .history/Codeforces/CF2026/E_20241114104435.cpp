#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 1e18;
constexpr int N = 1e5 + 10;
constexpr int M = 2e6 + 10;
int n, S, T, idx = 1, id, maxn;
int head[N], cur[N], dep[N];
struct Edge {
    int to, nxt, vol;
}e[M];
void init() {
    cin >> n;
    idx = 1;
    id = n + 61;
    maxn = n + 100;
    S = ++ id, T = ++ id;
    fill(head, head + maxn, 0);
    for (int i = 0; i <= 60; ++ i) addEdge(n + i + 1, T, 1);
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x;
        addEdge(S, i, 1);
        for (int j = 0; j <= 60; ++ j) if ((x >> j) & 1ll) addEdge(i, n + j + 1, INF);

    }
}
bool bfs() {
    queue<int> q;
    memset(dep, 0, (id) * sizeof(int));
    dep[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int u =  q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].vol && !dep[v]) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }  
    }
    return dep[T];
}
int dfs(int u, int flow) {
    if (u == T) return flow;
    memccpy(cur, head, (id + 1) * sizeof(int));
    int res{};
    for (int i = cur[u]; i && flow; i = e[i].nxt) {
        int v = e[i].to;
        if (e[i].vol && dep[v] == dep[u] + 1) {
            int dis = dfs(v, min(flow, e[i].vol));
            if (!dis) dep[v] = 0;
            flow -= dis;
            res += dis;
            e[i].vol -= dis;
            e[i ^ 1].vol +=dis;
            if (!flow) return res;
        }
    }
    if (!res) dep[u] = 0;
    return res;
}
int dinic() {
    int res{};
    while (bfs()) {

    }
}
void addEdge(int u, int v, int w) {
    e[idx] = {v, head[u], w}, head[u] = idx ++;
    e[idx] = {u, head[v], 0}, head[v] = idx ++;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}