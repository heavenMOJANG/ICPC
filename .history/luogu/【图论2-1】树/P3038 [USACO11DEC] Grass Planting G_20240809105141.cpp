#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, m, dep[N], dfn[N], siz[N], son[N], top[N], fa[N], idx, a[N], newA[N];
vector<int> g[N];
struct segmentTree {int sum, tag;} t[N << 2];
void apply(int p, int pl, int pr, int d) {
    t[p].tag += d;
    t[p].sum += (pr - pl + 1) * d;
}
void pushUp(int p) {t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;}
void pushDown(int p, int pl, int pr) {
    if (t[p].tag) {
        int mid = pl + pr >> 1;
        apply(p << 1, pl, mid, t[p].tag);
        apply(p << 1 | 1, mid + 1, pr, t[p].tag);
        t[p].tag = 0;
    }
}
void build(int p, int pl, int pr) {
    if (pl == pr) {
        t[p].sum = newA[pl];
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void update(int L, int R, int d, int p, int pl, int pr) {
    if (L <= pl && pr <= R) {
        apply(p, pl, pr, d);
        return;
    }
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1;
    if (L <= mid) update(L, R, d, p << 1, pl, mid);
    if (R > mid) update(L, R, d, p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return t[p].sum;
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1, res = 0;
    if (L <= mid) res += query(L, R, p << 1, pl, mid);
    if (R > mid) res += query(L, R, p << 1 | 1, mid + 1, pr);
    return res;
}
void dfs0(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u] = f;
    siz[u] = 1;
    for (auto v : g[u]) {
        if (v == f) continue;
        fa[v] = u;
        dfs0(v, u);
        siz[u] += siz[v];
        if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs1(int u, int topu) {
    dfn[u] = ++idx;
    newA[idx] = a[u];
    top[u] = topu;
    if (!son[u]) return;
    dfs1(son[u], topu);
    for (auto v : g[u]) {
        if (v != fa[u] && v != son[u]) dfs1(v, v);
    }
}
void updateRange(int u, int v, int d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(dfn[top[u]], dfn[u], d, 1, 1, n);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    //update(dfn[u], dfn[v], d, 1, 1, n);
}
int queryRange(int u, int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res += query(dfn[top[u]], dfn[u], 1, 1, n);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    res += query(dfn[u], dfn[v], 1, 1, n);
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1, 0);
    dfs1(1, 1);
    build(1, 1, n);
    while (m --) {
        string op; cin >> op;
        int u, v; cin >> u >> v;
        if (op[0] == 'P') updateRange(u, v, 1);
        else cout << queryRange(u, v) << "\n";
    }
    return 0;
}