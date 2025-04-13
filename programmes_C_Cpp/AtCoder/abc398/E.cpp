#pragma GCC optimie(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector a(n + 1, vector<int> (n + 1, 0));
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        a[u][v] = a[v][u] = 1;
    }
    vector<int> clr(n + 1, -1), vis(n + 1, 0);
    set<int> black, white;
    white.insert(1); clr[1] = 0;
    queue<int> q; q.push(1);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v : g[u]) {
            clr[v] = clr[u] ^ 1;
            if (clr[v]) black.insert(v);
            else white.insert(v);
            q.push(v);
        }
    }
    set<pair<int, int>> s;
    for (auto x : black)
        for (auto y : white) {
            if (!a[x][y]) s.insert({min(x, y), max(x, y)});
        }
    if (s.size() & 1) {
        cout << "First" << endl;
        auto [x, y] = *s.begin();
        cout << x << " " << y << endl;
        s.erase({x, y});
        int rx, ry;
        while (cin >> rx >> ry && rx && ry) {
            s.erase({min(rx, ry), max(rx, ry)});
            auto [x, y] = *s.begin();
            cout << x << " " << y << endl;
            s.erase({x, y});
        }
    } else {
        cout << "Second" << endl;
        int rx, ry;
        while (cin >> rx >> ry && rx && ry) {
            s.erase({min(rx, ry), max(rx, ry)});
            auto [x, y] = *s.begin();
            cout << x << " " << y << endl;
            s.erase({x, y});
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