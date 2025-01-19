#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> c[i];
    vector<int>g[n + 1];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> siz(n + 1), big(n + 1), L(n + 1), R(n + 1), Node(n + 1);
    int dfn = 0, tot = 0;
    vector<int> cnt(n + 1, 0), ans(n + 1);
    function<void(int)> add = [&](int u) {
        if (!cnt[c[u]]) ++ tot;
        cnt[c[u]] ++;
    };
    function<void(int)> del = [&](int u) {
        cnt[c[u]] --;
        if (cnt[c[u]]) --tot;
    };
    auto getAns = [&]() {return tot;};
    function<void(int, int)> dfs0 = [&](int u, int f) {
        L[u] = ++ dfn;
        Node[dfn] = u;
        siz[u] = 1;
        for (auto v : g[u])
            if (v != f) {
                dfs0(v, u);
                siz[u] += siz[v];
                if (!big[u] || siz[big[u]] < siz[v]) big[u] = v;
            }
        R[u] = dfn;
    };
    function<void(int, int, int)> dfs1 = [&](int u, int f, int keep) {
        for (auto v : g[u]) {
            if (v != f && v != big[u]) dfs1(v, u, 0);
        }
        if (big[u]) dfs1(big[u], u, 1);
        for (auto v : g[u])
            if (v != f && v  != big[u]) {
                for (int i = L[v]; i <= R[v]; ++ i) add(Node[i]);
            }
        add(u);
        ans[u] = getAns();
        if (!keep) {
            for (int i = L[u]; i <= R[u]; ++ i) del(Node[i]);
        }
    };
    dfs0(1, -1);
    dfs1(1, -1, 0);
    for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}