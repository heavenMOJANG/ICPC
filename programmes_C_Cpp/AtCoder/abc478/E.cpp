#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/scc>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct Edge { int t, u, v; };
void solve() {
    int N, Q; cin >> N >> Q;
    scc_graph g(N);
    vector<Edge> edges(Q);
    for (auto& [t, u, v] : edges) {
        cin >> t >> u >> v, u --, v --;
        g.add_edge(u, v);
    }
    auto groups = g.scc();
    int M{(int)groups.size()};
    vector<int> comp(N);
    for (int i : views::iota(0, M))
        for (int v : groups[i]) comp[v] = i;
    for (auto [t, u, v] : edges)
        if (t == 1 && comp[u] == comp[v]) { cout << "No\n"; return; }
    vector<vector<pair<int, int>>> dag(M);
    for (auto [t, u, v] : edges) {
        int U{comp[u]}, V{comp[v]};
        if (U != V) dag[U].emplace_back(V, t);
    }
    vector<int> dp(M, 1);
    for (int u : views::iota(0, M))
        for (auto [v, t] : dag[u])
            dp[v] = max(dp[v], dp[u] + t);
    cout << "Yes\n";
    for (int i : views::iota(0, N)) cout << dp[comp[i]] << " \n"[i + 1 == N];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}