#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct Edge { int to, nxt; } e[N << 1];
int n, head[N], idx, c[N], dfn[N], rev[N], cnt[N], son[N], tim, tot, siz[N];
void addEdge(int u, int v) {
    e[idx] = {v, head[u]}, head[u] = idx ++;
    e[idx] = {u, head[v]}, head[v] = idx ++;
}
void add(int u) {
    if (cnt[c[u]] == 0) tot ++;
    cnt[c[u]] ++;
}
void del(int u) {
    cnt[c[u]] --;
    if (cnt[c[u]] == 0) tot --;
}
int getAns() { return tot; }
void dfs0(int u, int fa) {
    dfn[u] = ++ tim;
    siz[u] = 1;
    rev[tim] = u;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    return 0;
}