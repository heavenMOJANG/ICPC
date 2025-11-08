#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    queue<int> q;
    vector<int> vis(n + 1, 0);
    vector<int> g[n + 1];
    for (int i = 1; i <= n; ++ i) {
        int a, b; cin >> a >> b;
        if (!a && !b) q.push(i);
        else {
            g[a].emplace_back(i);
            g[b].emplace_back(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        for (auto v : g[u]) {
            if (vis[v]) continue;
            q.push(v);
        }
    }
    int ans{};
    for (int i = 1; i <= n; ++ i) ans += vis[i];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}