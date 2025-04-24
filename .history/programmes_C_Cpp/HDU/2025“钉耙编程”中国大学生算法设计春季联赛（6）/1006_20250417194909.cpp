#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
vector<int> g[N];
int n, siz[N], ans[N];
int get(int x) { return x * (x - 1) / 2; }
void dfs(int u, int fa) {
    siz[u] = 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
void dfs1(int u, int fa) {
    int sz = g[u].size();
    vector<int> preS(n + 1), preC(n + 1);
    for (int i = 1; i <= n; ++ i) {
        if (g[u][i - 1] == fa) preS[i] = preS[i - 1] + siz[1] - siz[u];
        else preS[i] = preS[i - 1] + siz[g[u][i - 1]];
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, -1);
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}