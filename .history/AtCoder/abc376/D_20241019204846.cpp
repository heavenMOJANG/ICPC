#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1], dep(n + 1, 1), vis(n + 1, 0);
    for (int i = 1, u, v; i <= m; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    priority_queue<pair<int, int>> q;
    queue<int> q;
    q.push({dep[1], 1});
    while(!q.empty()) {
        int u = q.top().first; q.pop();
        if (vis[u]) {
            if (u != 1 || (u == 1 && dep[u] != 1)) continue;
        }
        vis[u] = 1;
        for (auto v : g[u]) {
            dep[v] = dep[u] + 1;
            q.push({dep[v], v});
        }
    }
    if (dep[1] == 1) cout << "-1\n";
    else cout << dep[1] - 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}