#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 300000 + 5;
constexpr int LOG = 20;

vector<int> g[MAXN];
int x[MAXN], y[MAXN];
int fa[MAXN][LOG], dep[MAXN];
int n;

/* DFS 建 parent 和 depth */
void dfs(int u) {
    for (int v : g[u]) {
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        for (int k = 1; k < LOG; ++k)
            fa[v][k] = fa[fa[v][k - 1]][k - 1];
        dfs(v);
    }
}

/* LCA */
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int k = 0; k < LOG; ++k)
        if (d >> k & 1)
            u = fa[u][k];
    if (u == v) return u;
    for (int k = LOG - 1; k >= 0; --k) {
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}

/* 找 u 在 lca 下面的下一步 */
int next_child(int u, int anc) {
    int d = dep[u] - dep[anc] - 1;
    for (int k = 0; k < LOG; ++k)
        if (d >> k & 1)
            u = fa[u][k];
    return u;
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; ++i) g[i].clear();

    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        g[x[i]].push_back(i);
    }

    dep[0] = 0;
    for (int k = 0; k < LOG; ++k) fa[0][k] = 0;
    dfs(0);

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);

    sort(ord.begin(), ord.end(), [&](int u, int v) {
        int w = lca(u, v);

        // u 是 v 的前缀
        if (w == u && w == v) return u < v;
        if (w == u) return true;
        if (w == v) return false;

        int cu = next_child(u, w);
        int cv = next_child(v, w);

        if (y[cu] != y[cv]) return y[cu] < y[cv];
        return u < v;
    });

    for (int i = 0; i < n; ++i)
        cout << ord[i] << " \n"[i + 1 == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
