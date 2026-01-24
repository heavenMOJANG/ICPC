#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
S op(S a, S b) { return a + b; }
S e() { return 0ll; }
vector<int> g[N];
int n, fa[N], dep[N], sz[N], son[N];
int top[N], dfn[N], rnk[N], out[N], tim;
void dfs0(int u, int p) {
    fa[u] = p;
    sz[u] = 1;
    son[u] = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs0(v, u);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs1(int u, int h) {
    top[u] = h;
    dfn[u] = ++tim;
    rnk[tim] = u;
    if (son[u] != -1) dfs1(son[u], h);
    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs1(v, v);
    }
    out[u] = tim;
}
int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) x = fa[top[x]];
        else y = fa[top[y]];
    }
    return dep[x] < dep[y] ? x : y;
}
int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
int up(int u, int k) {
    while (k) {
        int h = top[u];
        int d = dep[u] - dep[h];
        if (k <= d) return rnk[dfn[u] - k];
        k -= d + 1;
        u = fa[h];
    }
    return u;
}
int down(int u, int k) { return rnk[dfn[u] + k];}
int kth(int x, int y, int k) {
    int z = lca(x, y);
    int dx = dep[x] - dep[z];
    if (k <= dx) return up(x, k);
    k -= dx;
    int cur = y;
    int tg = dep[y] - dep[z] - k;
    return up(cur, tg);
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(0, -1);
    dfs1(0, 0);
    segtree<S, op, e> seg(n);
    int l{}, r{}, ans{};
    for (int mex{}; mex < n; mex ++) {
        int dl = dis(l, mex);
        int dr = dis(r, mex);
        int d = dis(l, r);
        if (dl > d) r = mex, d = dl;
        if (dr > d) l = mex, d = dr;
        int mid = kth(l, r, d / 2);
        long long cl{}, cr{};
        if (dfn[l] <= dfn[mid] - 1) cl = seg.prod(dfn[l] - 1, dfn[mid] - 1);
        if (dfn[mid] + 1 <= dfn[r]) cr = seg.prod(dfn[mid], dfn[r]);
        ans += cl * cr;
        int pos = dfn[mex] - 1;
        seg.set(pos, seg.get(pos) + 1);
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}