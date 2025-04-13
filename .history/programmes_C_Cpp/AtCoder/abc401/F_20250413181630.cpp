#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n1; cin >> n1;
    vector<vector<int>> g1(n1);
    for (int i = 1; i < n1; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g1[u].emplace_back(v);
        g1[v].emplace_back(u);
    }
    int n2; cin >> n2;
    vector<vector<int>> g2(n2);
    for (int i = 1; i < n2; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g2[u].emplace_back(v);
        g2[v].emplace_back(u);
    }
    vector<int> dep1u(n1, 0), dep1v = dep1u, dep2u(n2, 0), dep2v = dep1v;
    function<void(vector<vector<int>>, vector<int>&, int, int)> dfs = [&](vector<vector<int>> g, vector<int> & dep, int u, int fa) {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(g, dep, v, u);
        }
    };
    int maxn{}, u1{}, v1{}, u2{}, v2{};
    dep1u[0] = 1;
    dfs(g1, dep1u, 0, -1);
    for (int i{}; i < n1; ++ i) if (dep1u[i] > maxn) maxn = dep1u[i], u1 = i;
    fill(dep1u.begin(), dep1u.end(), 0);
    dep1u[u1] = 1;
    dfs(g1, dep1u, u1, -1);
    maxn = 0;
    for (int i{}; i < n1; ++ i) if (dep1u[i] > maxn) maxn = dep1u[i], v1 = i;
    dep1v[v1] = 1;
    dfs(g1, dep1v, v1, -1);
    vector<int> a(n1);
    for (int i{}; i < n1; ++ i) a.emplace_back(max(dep1u[i], dep1v[i]));
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}