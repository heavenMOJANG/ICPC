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
int instk[N], cut[N], addBlock[N], bdg;
vector<pair<int, int>> Lun, Qie, ans;
void addEdge(int u, int v, int id) {
    e[cnt] = {v, head[u], id, 0};
    head[u] = cnt ++;
}
void tarjan(int u, int f) {
    low[u] = dfn[u] = ++ idx;
    stk[top ++] = u;
    instk[u] = 1;
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
    instk[u] = 0;
    top --;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fill(head, head + N, -1);
    cin >> n >> m;

    return 0;
}