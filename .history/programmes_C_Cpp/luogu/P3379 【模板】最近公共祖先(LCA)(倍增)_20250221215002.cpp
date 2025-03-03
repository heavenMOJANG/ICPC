#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
int fa[N][31],dep[N];
vector<int> g[N];
int n, m, root;
void dfs(int u, int f){
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for(int i = 1; (1ll << i) <= dep[u]; ++ i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : g[u]) if (v != f) dfs(v, u);
}
int LCA(int u, int v){
    if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30; i >= 0; -- i) if (dep[u] - (1ll << i) >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 30; i >= 0; -- i) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> root;
    for(int i= 1, u, v; i < n; ++ i){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(root, 0);
    while(m --){
        int a,b; cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
    return 0;
}