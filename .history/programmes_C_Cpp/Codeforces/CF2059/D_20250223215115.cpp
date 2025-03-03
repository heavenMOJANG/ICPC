#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, s[2], m[2]; cin >> n >> s[0] >> s[1] >> m[0];
    s[0] --, s[1] --;
    vector<int> g[2][n];
    for (int i = 1, u, v; i <= m[0]; ++ i) {
        cin >> u >> v; u --, v --;
        g[0][u].emplace_back(v);
        g[0][v].emplace_back(u);
    }
    cin >> m[1];
    for (int i = 1, u, v; i <= m[1]; ++ i) {
        cin >> u >> v; u --, v --;
        g[1][u].emplace_back(v);
        g[1][v].emplace_back(u);
    }
    vector dis(n, vector<int>(n, INF));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, s[0], s[1]});
    dis[s[0]][s[1]] = 0;
    while (!pq.empty()) {
        auto [cst, x, y] = pq.top(); pq.pop();
        for (auto v0 : g[0][x])
            for (auto v1 : g[1][y]) {
                if (x == y && v0 == v1) { cout << cst << "\n"; return; }
                if (dis[v0][v1] > cst + abs(v0 - v1)) {
                    dis[v0][v1] = cst + abs(v0 - v1);
                    pq.push({dis[v0][v1], v0, v1});
                }
            }
    }
    cout << -1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}