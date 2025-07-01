#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, x; cin >> n >> m >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i <= n; ++ i) {
        int u, v, d; cin >> u >> v >> d;
        g[u].emplace_back(v, d);
    }
    unordered_map<int, vector<int>> sm;
    for (int i = 1; i <= n; ++ i) sm[a[i]].emplace_back(i);
    vector<array<int, 3>> dis(n + 1, {INF, INF, INF});
    unordered_map<int, array<bool, 3>> vis;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    dis[1][0] = 0;
    pq.emplace(0, 1, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}