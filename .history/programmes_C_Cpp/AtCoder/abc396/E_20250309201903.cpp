#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i <= m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> vis(n + 1, 0), val(n + 1, -1), ans(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        if (vis[i]) continue;
        val[i] = 0;
        queue<int> dq; dq.push_back(i);
        vis[i] = 1;
        vector<int> cmp; cmp.emplace_back(i);
        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            for (auto [v, w] : g[u])
                if (!vis[v]) {
                    vis[v] = 1;
                    val[v] = val[u] ^ w;
                    cmp.emplace_back(v);
                    dq.push_back(v);
                } else if (val[v] != val[u] ^ w) { cout << "-1\n"; return; }
        }
        for (int j = 0; j < 30; ++ j) {
            int cnt{};
            for (auto x : cmp) if (val[x] & (1ll << j)) cnt ++;
            if (cnt < cmp.size() - cnt)
                for (auto x : cmp) if (val[x] & (1ll << j)) ans[x] |= 1ll << j;
            else
                for (auto x : cmp) if (!(val[x] & (1ll << j))) ans[x] |= 1ll << j;
        }
    }
    for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}