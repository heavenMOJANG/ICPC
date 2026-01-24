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
        for (int i{}; i < n; ++ i) {
            if (fa[i][j - 1] != -1) fa[i][j] = fa[fa[i][j - 1]][j - 1];
            else fa[i][j] = -1;
        }
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
    auto on_path = [&](int a, int b, int c) { return dis(a, b) + dis(b, c) == dis(a, c); };
    auto jump = [&](int u, int v) {
        for (int j = 19; ~j; -- j) {
            if (fa[u][j] != -1 && dis(fa[u][j], v) + 1 == dis(u, v)) u = fa[u][j];
        }
        return u;
    };
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, 0);
    int ans = 0;
    int u = 0, v = 0;
    for (int mex = 1; mex <= N; ++ mex) {
        int count = 0;
        int p = lca(u, v);
        if (u == v) {
            int bad_paths = 0;
            for(int child : g[0]) {
                int s = sz[child];
                bad_paths += s * (s + 1) / 2;
            }
            int total_paths = (int)N * (N + 1) / 2;
            count = total_paths - bad_paths;
        } else {
            int sz_u = sz[u], sz_v = sz[v];
            if (p == u) {
                int child = jump(v, u);
                sz_u = N - sz[child];
            }
            else if (p == v) {
                int child = jump(u, v);
                sz_v = N - sz[child];
            }
            count = sz_u * sz_v;
        }
        ans += count;
        if (mex == N) break;
        if (on_path(u, v, mex)) continue;
        if (on_path(mex, v, u)) u = mex;
        else if (on_path(u, mex, v))v = mex;
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