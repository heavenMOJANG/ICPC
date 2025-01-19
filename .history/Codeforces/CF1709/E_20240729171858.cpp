#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> g[n + 1];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int idx = 0, ans = 0;
    vector<int> siz(n + 1, 0), son(n + 1, 0), dfn(n + 1, 0), ctr(n + 1, 0), rnk(n + 1, 0), dis(n + 1, 0), flag(n + 1, 0);
    map<int, int>cnt;
    function<void(int)> add = [&](int u) {
        cnt[a[u]] ++;
    };
    function<void(int)> del = [&](int u) {
        cnt[a[u]] --;
    };
    function<void(int, int)> dfs0 = [&](int u, int f) {
        dfn[u] = ++ idx;
        siz[u] = 1;
        rnk[idx] = u;
        dis[u] = a[u] ^ dis[f];
        for (auto v : g[u]) {
            if (v != f) {
                dfs0(v, u);
                siz[u] += siz[v];
                if (siz[son[u]] < siz[v]) son[u] = v;
            }
        }
        ctr[u] = idx;
    };
    function<int(int, int)> check = [&](int u, int f) {
        return cnt[dis[u] ^ a[f]] ? 0 : 1;
    };
    function<void(int, int, int)> dfs1 = [&](int u, int f, int keep) {
        for (auto v : g[u])
            if (v != f && v != son[u]) dfs1(v, u, 0);
        if (son[u]) dfs1(son[u], u, 1);
        for (auto v : g[u]) {
            if (v != f && v != son[u]) {
                for (int i = dfn[v]; i <= ctr[v]; ++ i) {
                    if (flag[rnk[i]]) {
                        i = ctr[rnk[i]];
                        continue;
                    }
                    if (!check(rnk[i], u)) flag[u] = 1;
                }
                for (int i = dfn[u]; i <= ctr[v]; ++ i) {
                    if (flag[rnk[i]]) {
                        i = ctr[rnk[i]];
                        continue;
                    }
                    add(rnk[i]);
                }
            }
        }
        if (!check(u, u)) flag[u] = 1;
        add(u);
        if (!keep || flag[u]) 
            for (int i = dfn[u]; i <= ctr[i]; ++ i) cnt.clear();
    };
    dfs0(1, 0);
    dfs1(1, 0, 1);
    for(int i = 1; i <= n; ++ i) if (flag[i]) ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}