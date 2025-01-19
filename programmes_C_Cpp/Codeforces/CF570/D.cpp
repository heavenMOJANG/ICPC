#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for (int v = 2, u; v <= n; ++ v) {
        cin >> u;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    string s; cin >> s;
    s = " " + s;
    vector<int> siz(n + 1, 0), dfn(n + 1 ,0), son(n + 1, 0), ctr(n + 1, 0), rnk(n + 1, 0), son(n + 1, 0);
    int idx = 0;
    auto add = [&](int u) {mp[s[u]] ++;};
    auto del = [&](int u) {mp[s[u]] --;};
    function<void(int, int)> dfs0 = [&](int u, int f) {
        dfn [u] = ++ idx;
        siz [u] = 1;
        rnk [idx] = u;
        for (auto v : g[u]) {
            if (v != f) {
                dfs0(v, u);
                siz[u] += siz[v];
                if (siz[son[u] > siz[v]) son[u] = v;
            }
        }
        ctr[u] = idx;
    };
    function<void(int, int, int)> dfs1 = [&](int u, int f, int keep) {
        
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}