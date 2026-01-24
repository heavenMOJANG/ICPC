#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
const int N = 2e5 + 10;
void solve() {
    int n; cin >> n;
    vector<int> g[n], dep(n), sz(n);
    vector fa(n, vector<int>(20, -1));
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        dep[u] = d;
        fa[u][0] = p;
        sz[u] = 1;
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
                sz[u] += sz[v];
            }
        }
    };
    for (int j = 1; j < 20; ++ j)
        for (int i{}; i < n; ++ i)
            if (fa[i][j - 1] != -1) fa[i][j] = fa[fa[i][j - 1]][j - 1];
            else fa[i][j] = -1;
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int j = 19; ~j; -- j) {
            if (fa[u][j] != -1 && dep[fa[u][j]] >= dep[v]) u = fa[u][j];
        }
        if (u == v) return u;
        for (int j = 19; ~j; -- j)
            if (fa[u][j] != fa[v][j]) u = fa[u][j], v = fa[v][j];
        return fa[u][0];
    };
    auto dis = [&](int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; };
    auto on = [&](int a, int b, int c) { return dis(a, b) + dis(b, c) == dis(a, c); };
    auto jump = [&](int u, int v) {
        for (int j = 19; ~j; -- j)
            if (fa[u][j] != -1 && dis(fa[u][j], v) + 1 == dis(u, v)) u = fa[u][j];
        return u;
    };
    for (int i{}; i < n - 1; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0, -1, 0);
    int ans{}, l{}, r{};
    for (int mex = 1; mex <= n; ++ mex) {
        int cnt{}, p = lca(l, r);
        if (l == r) {
            int tmp{};
            for(int v : g[0]) tmp += sz[v] * (sz[v] + 1) / 2;
            int tot = n * (n + 1) / 2;
            cnt = tot - tmp;
        } else {
            int cl = sz[l], cr = sz[l];
            if (p == l) {
                int son = jump(r, l);
                cl = n - sz[son];
            }
            else if (p == r) {
                int son = jump(l, r);
                cr = n - sz[son];
            }
            cnt = cl * cr;
        }
        ans += cnt;
        if (mex == N) break;
        if (on(l, r, mex)) continue;
        if (on(mex, r, l)) l = mex;
        else if (on(l, mex, r)) r = mex;
        else break;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}