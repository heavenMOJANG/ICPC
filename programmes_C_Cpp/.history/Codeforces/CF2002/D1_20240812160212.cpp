#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> g[n + 1];
    for (int v = 2, u; v <= n; ++ v) cin >> u, g[u].emplace_back(v);
    vector<int> dep(n + 1, 0);
    vector fa(n + 1, vector<int>(20, 0));
    // Get the depth of each node
    function <void(int, int)> dfs = [&](int u, int f) {
        dep[u] = dep[f] + 1;
        fa[u][0] = f;
        for (int i = 1; i < 20; ++ i)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (auto v : g[u]) dfs(v, u);
    };
    dfs(1, 0);
    
    function<int(int, int)> lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; i >= 0; -- i)
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        if (u == v) return u;
        for (int i = 19; i >= 0; -- i) {
            if (fa[u][i] == fa[v][i]) continue;
            u = fa[u][i];
            v = fa[v][i];
        }
        return fa[u][0];
    };
    function<int(int, int)> getDis = [&](int u, int v) {
        return min(u, v) > 0 ? dep[u] + dep[v] - 2 * dep[lca(u, v)] : 0;
    };
    vector<int> a(n + 2);
    function<int(int)> check = [&](int u) {
        return 0 < u && u < n ? lca(a[u], a[u + 1]) == a[u + 1] : 0;
    };
    int len = 0, sum = 0;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        len += getDis(a[i], a[i - 1]);
        sum += check(i - 1);
    }
    a[n + 1] = 0;
    while (q --) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        len -= getDis(a[u], a[u - 1]);
        len -= getDis(a[u], a[u + 1]);
        len -= getDis(a[v], a[v - 1]);
        len -= getDis(a[v], a[v + 1]);
        sum -= check(u - 1);
        sum -= check(u);
        if (u + 1 != v) sum -= check(v - 1);
        sum -= check(v);
        swap(a[u], a[v]);
        len += getDis(a[u], a[u - 1]);
        len += getDis(a[u], a[u + 1]);
        len += getDis(a[v], a[v - 1]);
        len += getDis(a[v], a[v + 1]);
        sum += check(u - 1);
        sum += check(u);
        if (u + 1 != v) sum += check(v - 1);
        sum += check(v);
        if (sum == 0 && len + dep[a[n]] - 1 == 2 * n - 2) cout << "YES\n";
        else cout << "NO\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}