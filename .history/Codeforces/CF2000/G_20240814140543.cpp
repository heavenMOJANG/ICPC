#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {int v, w1, w2;};
void solve() {
    int n, m, t0, t1, t2; cin >> n >> m >> t0 >> t1 >> t2;
    vector<Node> g[n + 1];
    for (int i = 0; i < m; ++ i) {
        int u, v, w1, w2; cin >> u >> v >> w1 >> w2;
        g[u].emplace_back(v, w1, w2);
        g[v].emplace_back(u, w1, w2);
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}