#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), to(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= n; ++ i) cin >> to[i];
    vector<int> dis(n + 1, INF), vis(n + 1, 0);
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i <= n; ++ i) {
        g[i].emplace_back(to[i], a[i]);
        if (i != 1) g[i].emplace_back(i - 1, 0);
    }
    priority_queue<pair<int, int>> pq;
    pq.push({dis[1] = 0, 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {

        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}