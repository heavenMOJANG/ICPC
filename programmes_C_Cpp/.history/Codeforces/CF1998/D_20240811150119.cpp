#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) g[i].emplace_back(i + 1, 1);
    for (int i = 0, u, v; i < m; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    vector<int> dis(n + 1, -1), p(n + 1, 0);
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u])
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
    vector<char> ans(n + 1);
    for (int i = 2; i < n; ++ i) cout << dis[i] << " ";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}