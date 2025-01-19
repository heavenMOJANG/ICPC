#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int id, d;
    bool operator < (const Node & x) const {return d > x.d;}
};
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i < n; ++ i) g[i].emplace_back(i + 1, 1);
    for (int i = 0, u, v; i < m; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v, 1);
    }
    vector<int> dis(n + 1, INF);
    priority_queue<Node> pq;
    pq.push({1, dis[1] = 0});
    while (!pq.empty()) {
        Node
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}