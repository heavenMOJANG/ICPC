#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct Edge { int to, nxt; } e[N << 1];
int head[N], idx;
int n, c[N], ans[N];
int dfn[N], rev[N], cnt[N], son[N], tim, tot, siz[N];
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
        dfs0(v, u);
        siz[u] += siz[v];
        if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs1(int u, int fa, int keep) {
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa || v == son[u]) continue;
        dfs1(v, u, 0);
    }
    if (son[u]) dfs1(son[u], u, 1);
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa || v == son[u]) continue;
        for (int j = dfn[v]; j <= dfn[v] + siz[v] - 1; ++ j) add(rev[j]);
    }
    add(u);
    ans[u] = getAns();
    if (!keep) for (int j = dfn[u]; j <= dfn[u] + siz[u] - 1; ++ j) del(rev[j]);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    return 0;
}