#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x7fffffff;
const int N = 3e5 + 10;
struct Edge { int to, nxt; } e[N << 1];
struct Node { int val, tag; } t[N << 2];
int n, m, rt, mod, w[N];
int head[N], idx;
int son[N], dfn[N], fa[N], dep[N], siz[N], top[N], rev[N], tim;
void addEdge(int u, int v){
    e[idx] = {v, head[u]}, head[u] = idx ++;
    e[idx] = {u, head[v]}, head[v] = idx ++;
}
void dfs0(int u, int fat){
    dep[u] = dep[fat]+1;
    fa[u] = fat;
    siz[u] = 1;
    for (int i= head[u]; ~i ; i = e[i].nxt){
        int v = e[i].to;
        if (v != fat) {
            fa[v] = u;
            dfs0(v, u);
            siz[u] += siz[v];
            if(!son[u] || siz[son[u]] < siz[v]) son[u] = v;
        }
    }
}
void dfs1(int u, int t){
    dfn[u] = ++ tim;
    rev[tim] = w[u];
    top[u] = t;
    if (!son[u]) return;
    dfs1(son[u], t);
    for (int i = head[u]; ~i; i = e[i].nxt) {
        int v = e[i].to;
        if(v != fa[u] && v != son[u]) dfs1(v, v);
    }
}
void pushUp(int p) { (t[p].val = t[p << 1].val + t[p << 1 | 1].val) %= mod; }
void addTag(int p, int pl, int pr, int d) {
    (t[p].tag += d) %= mod;
    (t[p].val += d * (pr - pl + 1)) %= mod;
}
void pushDown(int p, int pl, int pr){
    if (t[p].tag) {
        int mid = pl + pr >> 1;
        addTag(p << 1, pl, mid, t[p].tag);
        addTag(p << 1 | 1, mid + 1, pr, t[p].tag);
        t[p].tag = 0;
    }
}
void build (int p, int pl, int pr) {
    if (pl == pr) {
        t[p] = { rev[pl] % mod, 0 };
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void update(int L, int R, int p, int pl, int pr, int d) {
    if (L <= pl && pr <= R) {
        addTag(p, pl, pr, d);
        return;
    }
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1;
    if (L <= mid) update(L, R, p << 1, pl, mid, d);
    if (R > mid) update(L, R, p << 1 | 1, mid + 1, pr, d);
    pushUp(p);
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return t[p].val % mod;
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1, res{};
    if (L <= mid) (res += query(L, R, p << 1, pl, mid)) %= mod;
    if (R > mid) (res += query(L, R, p << 1 | 1, mid + 1, pr)) %= mod;
    return res;
}
void updateRange(int u, int v, int d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(dfn[top[u]], dfn[u], 1, 1, n, d);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    update(dfn[u], dfn[v], 1, 1, n, d);
}
int queryRange(int u, int v) {
    int res{};
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        (res += query(dfn[top[u]], dfn[u], 1, 1, n)) %= mod;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return (res += query(dfn[u], dfn[v], 1, 1, n)) %= mod;
}
void updateTree(int u, int d) { update(dfn[u], dfn[u] + siz[u] - 1, 1, 1, n, d); }
int queryTree(int u) { return query(dfn[u], dfn[u] + siz[u] - 1, 1, 1, n); }
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    fill(head, head + N, -1);
    cin >> n >> m >> rt >> mod;
    for (int i = 1; i <= n; ++ i) cin >> w[i];
    for(int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        addEdge(u, v);
    }
    dfs0(rt, 0);
    dfs1(rt, rt);
    build(1, 1, n);
    while(m --){
        int opt, x, y, z; cin >> opt;
        switch(opt){
            case 1:
                cin >> x >> y >> z;
                updateRange(x, y, z);
                break;
            case 2:
                cin >> x >> y;
                cout << queryRange(x, y) << "\n";
                break;
            case 3:
                cin >> x >> z;
                updateTree(x, z);
                break;
            case 4:
                cin >> x;
                cout << queryTree(x) << "\n";
                break;
        }
    }
    return 0;
}