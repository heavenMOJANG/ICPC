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
void addEdge(int u, int v, int id) {
    e[cnt] = {v, head[u], id, 0};
    head[u] = cnt ++;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}