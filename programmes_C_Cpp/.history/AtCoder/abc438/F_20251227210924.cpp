#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
vector<int> g[N];
int n;
int fa[20][N], dep[N], sz[N], son[N];
int top[N], dfn[N], out[N], rin[N], tim;
void dfs0(int u, int p) {
    fa[0][u] = p;
    sz[u] = 1;
    son[u] = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs0(v, u);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[v] > sz[son[u]])
            son[u] = v;
    }
}

void dfs1(int u, int h) {
    top[u] = h;
    dfn[u] = ++ tim;
    rin[tim] = u;
    if (son[u] != -1)
        dfs1(son[u], h);
    for (int v : g[u]) {
        if (v == fa[0][u] || v == son[u]) continue;
        dfs1(v, v);
    }
    out[u] = tim;
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; --i)
        if (fa[i][x] != -1 && dep[fa[i][x]] >= dep[y])
            x = fa[i][x];
    if (x == y) return x;
    for (int i = 19; i >= 0; --i)
        if (fa[i][x] != fa[i][y])
            x = fa[i][x], y = fa[i][y];
    return fa[0][x];
}

int dis(int x, int y) {
    int z = lca(x, y);
    return dep[x] + dep[y] - 2 * dep[z];
}

/* Fenwick */
struct BIT {
    int t[N];
    void add(int x, int v) {
        for (; x <= n; x += x & -x) t[x] += v;
    }
    int sum(int x) {
        int r = 0;
        for (; x; x -= x & -x) r += t[x];
        return r;
    }
    int range(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
} bit;

int path_pos(int x, int y, int k) {
    // kth node from x to y (0-indexed)
    int z = lca(x, y);
    int dx = dep[x] - dep[z];
    if (k <= dx) {
        for (int i = 19; i >= 0; --i)
            if ((1LL << i) <= k) {
                x = fa[i][x];
                k -= (1LL << i);
            }
        return x;
    }
    k = dep[y] - dep[z] - (k - dx);
    for (int i = 19; i >= 0; --i)
        if ((1LL << i) <= k) {
            y = fa[i][y];
            k -= (1LL << i);
        }
    return y;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) g[i].clear();

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(fa, -1, sizeof fa);
    dep[0] = 0;
    dfs0(0, -1);
    for (int j = 1; j < 20; ++j)
        for (int i = 0; i < n; ++i)
            fa[j][i] = (fa[j - 1][i] == -1) ? -1 : fa[j - 1][fa[j - 1][i]];

    tim = 0;
    dfs1(0, 0);

    int l = 0, r = 0;
    int ans = 0;

    for (int mex = 0; mex < n; ++mex) {
        if (dis(l, mex) > dis(l, r)) r = mex;
        if (dis(r, mex) > dis(l, r)) l = mex;

        int d = dis(l, r);
        int mid = path_pos(l, r, d / 2);

        int left = bit.range(dfn[l], dfn[mid] - 1);
        int right = bit.range(dfn[mid] + 1, dfn[r]);

        ans += left * right;

        bit.add(dfn[mex], 1);
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
