#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[3 * n + 1];
    int ok = 1;
    vector<int> in(3 * n + 1, 0);
    for (int i = 0; i < m; ++ i) {
        int x, y, col; cin >> x >> y >> col;
        int v0 = (y + 1) / 2, v1 = 2 * n - x + 1, v2 = 2 * n + x - y / 2;
        if (col == v0) {
            g[v1].emplace_back(v0);
            g[v2].emplace_back(v0);
            in[v0] += 2;
            continue;
        }
        if (col == v1) {
            g[v0].emplace_back(v1);
            g[v2].emplace_back(v1);
            in[v1] += 2;
            continue;
        }
        if (col == v2) {
            g[v0].emplace_back(v2);
            g[v1].emplace_back(v2);
            in[v2] += 2;
            continue;
        }
        ok = 0;
    }
    if (!ok) { cout << "No\n"; return; }
    queue<int> q;
    for (int i = 1; i <= 3 * n; ++ i) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u]) {
            in[v] --;
            if (!in[v]) q.push(v);
        }
    }
    for (int i = 1; i <= 3 * n; ++ i) if (in[i]) { cout << "No\n"; return; }
    cout << "Yes\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}