#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x7fffffff;
const int N = 1e5 + 10;
int n, c[N], siz[N], son[N], dfn[N], rev[N], idx, tot, maxn, cnt[N], ans[N];
vector<int> g[N];
void add(int u) {
    cnt[c[u]] ++;
    if (cnt[c[u]] > maxn) {
        maxn = cnt[c[u]];
        tot = c[u];
    } else
        if (cnt[c[u]] == maxn) tot += c[u];
}
void del(int u) { cnt[c[u]] --; }
int getAns() { return tot; }
void dfs0(int u, int f) {
    dfn[u] = ++ idx;
    rev[idx] = u;
    siz[u] = 1;
    for (int i = 0; i < g[u].size(); ++ i) {
        int v = g[u][i];
        if (v != f) {
            dfs0(v, u);
            siz[u] += siz[v];
            if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
        }
    }
}
void dfs1(int u, int f, int keep) {
    for (int i = 0; i < g[u].size(); ++ i) {
        int v = g[u][i];
        if (v != f && v != son[u]) dfs1(v, u, 0);
    }
    if (son[u]) dfs1(son[u], u, 1);
    for (int i = 0; i < g[u].size(); ++ i) {
        int v = g[u][i];
        if (v != f && v != son[u]) {
            for (int i = dfn[v]; i <= dfn[v] + siz[v] - 1; ++ i) add(rev[i]);
        }
    }
    add(u);
    ans[u] = getAns();
    if (!keep) {
        for (int i = dfn[u]; i <= dfn[u] + siz[u] - 1; ++ i) del(rev[i]);
        tot = maxn = 0;
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> c[i];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs0(1, -1);
    dfs1(1, -1, 1);
    for (int i = 1; i <= n; ++ i) cout << ans[i] << endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("9.in", "r", stdin);
    freopen("9.out", "w", stdout);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}