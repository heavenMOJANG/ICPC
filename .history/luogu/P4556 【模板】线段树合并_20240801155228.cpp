#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, m, f[N][22], dep[N], rt[N], idx, ans[N];
struct Node {
    int sum, res, l, r;
}t[N << 6];
vector<int> g[N];
void update(int u) {
    if (t[t[u].l].sum < t[t[u].r].sum) {
        t[u].res = t[t[u].r].res;
        t[u].sum = t[t[u].r].sum;
    } else {
        t[u].res = t[t[u].l].res;
        t[u].sum = t[t[u].l].sum;
    }
}
int merge(int u, int v, int pl, int pr) {
    if (!u) return v;
    if (!v) return u;
    if (pl == pr) {
        t[u].sum += t[v].sum;
        return u;
    }
    int mid = pl + pr >> 1;
    t[u].l = merge(t[u].l, t[v].l, pl, mid);
    t[u].r = merge(t[u].r, t[v].r, mid + 1, pr);
    update(u);
    return u;
}
int add(int p, int pl, int pr, int co, int val) {
    if (!p) p = ++ idx;
    if (pl == pr) {
        t[p].sum +=val;
        t[p].res = co;
        return p;
    }
    int mid = pl + pr >> 1;
    if (co <= mid) t[p].l = add(t[p].l, pl, mid, co, val);
    else t[p].r = add(t[p].r, mid + 1, pr, co, val);
    update(p);
    return p;
}
void initLca(int u) {
    for (int i = 0; i <= 20; ++ i) f[u][i + 1] = f[f[u][i]][i];
    for (int v : g[u]) {
        if (v == f[u][0]) continue;
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        initLca(v);
    }
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int d = dep[x] - dep[y], i = 0; d; d >>= 1, ++ i)
        if (d & 1) x = f[x][i];
    if (x == y) return x;
    for (int i = 20; i >= 0; -- i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
void cacl(int u) {
    for (auto v : g[u]) {
        if (v == f[u][0]) continue;
        cacl(v);
        rt[u] = merge(rt[u], rt[v], 1, 100000);
    }
    ans[u] = t[rt[u]].res;
    if (t[rt[u]].sum == 0) ans[u] = 0;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, u, v; i < n - 1; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    initLca(1);
    for (int i = 0, a, b, c; i < m; ++ i) {
        cin >> a >> b >> c;
        rt[a] = add(rt[a], 1, 100000, c, 1);
        rt[b] = add(rt[b], 1, 100000, c, 1);
        int t = lca(a, b);
        rt[t] = add(rt[t], 1, 100000, c, -1);
        rt[f[t][0]] = add(rt[f[a][0]], 1, 100000, c, -1);
    }
    cacl(1);
    for (int i = 1; i <= n; ++ i) cout << ans[i] << "\n";
    return 0;
}