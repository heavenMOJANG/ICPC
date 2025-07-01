#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, l; cin >> n >> m >> l;
    vector<int> a(l);
    for (int i{}; i < n; ++ i) cin >> a[i];
    vector<int> g[n];
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector dis(n, vector<int> (2, INF));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0][0] = 0;
    while (!q.empty()) {
        auto [u, f] = q.front(); q.pop();
        for (auto v: g[u])
            if (dis[v][f ^ 1] == INF) {
                dis[v][f ^ 1] = dis[u][f] + 1;
                q.push({v, f ^ 1});
            }
    }
    int sum = accumulate(a.begin(), a.end(), 0ll);
    vector<int> maxn(2){0, -1};
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}