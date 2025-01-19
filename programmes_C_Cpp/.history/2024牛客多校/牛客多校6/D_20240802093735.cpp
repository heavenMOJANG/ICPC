#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct Edge {int to, nxt, id, cut;}e[N << 2];
int n, m;
int f[N], siz[N];
int head[N], cnt;
int dfn[N], low[N], stk[N], idx, top;
int cut[N], addBlock[N], bdg;
vector<pair<int, int>> Lun, Qie, ans;
void addEdge(int u, int v, int id) {
    e[cnt] = {v, head[u], id, 0};
    head[u] = cnt ++;
}
void tarjan(int u, int f) {
    low[u] = dfn[u] = ++ idx;
    stk[top ++] = u;
    int son = 0, preCnt = 0;
    for (int i = head[u]; ~i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == f && preCnt == 0) {preCnt ++; continue;}
        if (!dfn[v]) {
            son ++;
            tarjan(v, u);
            if (low[u] > low[v]) low[u] = low[v];
            if (low[v] > dfn[u]) {
                bdg ++;
                e[i].cut = 1;
                e[i ^ 1].cut = 1; 
            }
            if (u != f && low[v] >= dfn[u]) {
                cut[u] = 1;
                addBlock[u] ++;
            } else if (low[u] > dfn[v]) low[u] = dfn[v];
        }
    }
    if (u == f && son > 1) cut[u] = 1;
    if (u == f) addBlock[u] = son - 1;
    top --;
}
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)  return;
    if (siz[x] < siz[y]) f[x] = y, siz[y] += siz[x];
    f[y] = x, siz[x] += siz[y];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fill(head, head + N, -1);
    fill(siz, siz + N, 1);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) f[i] = i;
    for (int i = 0, u, v; i < m; ++ i) {
        string s; cin >> u >> v >> s;
        if (s[0] == 'L') Lun.emplace_back(u, v);
        else Qie.emplace_back(u, v);
    }
    for (int i = 0; i < Lun.size(); ++ i) {
        auto [u, v] = Lun[i];
        addEdge(u, v, i);
        addEdge(v, u, - 1);
    }
    for (int i = 1; i <= n; ++ i) if (!dfn[i]) tarjan(i, i);
    for (int i = 1; i <= n; ++ i)
        for (int j = head[i]; ~j;) {
            auto [to, nxt, id, cut] = e[j];
            if (e[j].id < 0 || e[j].cut) {j = e[j].nxt; continue;}
            merge(i, e[j].to);
            ans.emplace_back(i ,e[j].to);
            j = nxt;
        }
    for (auto [u, v] : Qie) {
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        ans.emplace_back(u, v);
        merge(u, v);
    }
    if (siz[find(1)] != n) {cout << "NO\n";return 0;}
    cout << "YES\n" << ans.size() << "\n";
    for (auto [u, v] : ans) cout << u << " " << v << "\n";
    return 0;
}