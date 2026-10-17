#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int minC, maxC; };
S op(S a, S b) { return {min(a.minC, b.minC), max(a.maxC, b.maxC)}; }
S e() { return {INF, -INF}; }
int N, Q;
vector<int> W, C;
vector<vector<int>> G;
vector<int> fat, dep, siz, top, dfn, rnk;
int idx{};
void dfs0(int u, int f) {
    siz[u] = 1;
    fat[u] = f;
    for (int v : G[u]) {
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        dfs0(v, u);
        siz[u] += siz[v];
        if (G[u][0] == f || siz[v] > siz[G[u][0]]) swap(v, G[u][0]);
    }
}
void dfs1(int u, int f) {
    dfn[u] = ++ idx;
    rnk[dfn[u]] = u;
    for (int v : G[u]) {
        if (v == f) continue;
        top[v] = (v == G[u][0] ? top[u] : v);
        dfs1(v, u);
    }
}
vector<int> f, ls;
void dfs(int u, int f) {
    f[u] =
}
void solve() {
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
