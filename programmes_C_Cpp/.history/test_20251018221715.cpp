#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto bfs = [&](int s) {
        vector<int> dist(n + 1, -1);
        queue<int> wznork;
        wznork.push(s);
        dist[s] = 0;
        int p = s;
        while (!wznork.empty()) {
            int u = wznork.front();
            wznork.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    wznork.push(v);
                    if (dist[v] > dist[p] || (dist[v] == dist[p] && v > p)) {
                        p = v;
                    }
                }
            }
        }
        return p;
    };
    for (int i = 1; i <= n; ++i) {
        cout << bfs(i) << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}