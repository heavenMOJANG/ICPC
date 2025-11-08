#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto bfs = [&](int s) {
        vector<int> dist(n + 1, -1);
        queue<int> wznork; wznork.push(s);
        dist[s] = 0;
        while (!wznork.empty()) {
            int u = wznork.front(); wznork.pop();
            for (int v : g[u])
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    wznork.push(v);
                }
        }
        int p = s;
        for (int i = 1; i <= n; ++i) if (dist[i] > dist[p] || (dist[i] == dist[p] && i > p)) p = i;
        return make_pair(p, dist);
    };
    auto [u, disu] = bfs(1);
    auto [v, disv] = bfs(u);
    for (int i = 1; i <= n; ++i)
        if (disu[i] > disv[i] || (disu[i] == disv[i] && u > v)) cout << u << "\n";
        else cout << v << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}