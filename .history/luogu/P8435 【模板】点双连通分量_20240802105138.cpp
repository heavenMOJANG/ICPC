#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10, M = 2e6 + 10;
struct Edge {int to, nxt;} e[M << 1];
int n, m, head[N], idx = 1, ans;
int dfn[N], low[N], timeStamp, cut[N], cnt, stk[N], top;
vector<int> dcc[N];
void addEdge(int u, int v) {e[++ idx] = {v, head[u]}; head[u] = idx;}
void tarjan(int u, int f) {
    dfn[u] = low[u] = ++ timeStamp;
    stk[++ top] = u;
    if (u == f && !head[u]) {
        dcc[++ cnt].emplace_back(u);
        return;
    }
    int f = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (!dfn[v]) {
            tarjan(v, f);
            low[u] = min(low[u], low[v]);
            if (++ f > 1 || u != f) cut[u] = 1;
            cnt ++;
            do {
                dcc[cnt].emplace_back(stk[top --]);
            } while (stk[top + 1] != v);
            dcc[cnt].emplace_back(u);
        } else low[u] = min(low[u], dfn[v]);
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++ i) {
        cin >> u >> v;
        if (u == v) continue;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; ++ i)
        if (!dfn[i]) tarjan(i, i);
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; ++ i) {
        cout << dcc[i].size() << "\n";
        for (auto x : dcc[i]) cout << " " << x;
        cout << "\n";
    }
    return 0;
}