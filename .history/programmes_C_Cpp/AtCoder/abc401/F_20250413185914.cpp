#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
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
    dfs(g1, dep1u, 0, -1);
    for (int i{}; i < n1; ++ i) if (dep1u[i] > maxn) maxn = dep1u[i], u1 = i;
    fill(dep1u.begin(), dep1u.end(), 0);
    dep1u[u1] = 0;
    dfs(g1, dep1u, u1, -1);
    maxn = 0;
    for (int i{}; i < n1; ++ i) if (dep1u[i] > maxn) maxn = dep1u[i], v1 = i;
    int d1 = maxn;
    dfs(g1, dep1v, v1, -1);
    vector<int> a(n1);
    for (int i{}; i < n1; ++ i) a.emplace_back(max(dep1u[i], dep1v[i]));

    maxn = 0;
    dfs(g2, dep2u, 0, -1);
    for (int i{}; i < n2; ++ i) if (dep2u[i] > maxn) maxn = dep2u[i], u2 = i;
    fill(dep2u.begin(), dep2u.end(), 0);
    dep2u[u2] = 1;
    dfs(g2, dep2u, u2, -1);
    maxn = 0;
    for (int i{}; i < n2; ++ i) if (dep2u[i] > maxn) maxn = dep2u[i], v2 = i;
    int d2 = maxn;
    dfs(g2, dep2v, v1, -1);
    vector<int> b(n2);
    for (int i{}; i < n2; ++ i) b.emplace_back(max(dep2u[i], dep2v[i]));

    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}