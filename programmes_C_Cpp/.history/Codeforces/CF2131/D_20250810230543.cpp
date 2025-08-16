#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    if (n == 2) { cout << "0\n"; return; }
    vector<int> fa(n + 1, 0), siz(n + 1, 0), lea(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int f) {
        fa[u] = f;
        siz[u] = 1;
        int son{}, lv{};
        for (int v : g[u]) {
            if (v == f) continue;
            son ++;
            dfs(v, u);
            siz[u] += siz[v];
            lv += lea[v];
        }
        if (son == 0) lea[u] = 1;
        else lea[u] = lv;
    };
    dfs(1, 0);
    int tot{};
    for (int i = 1; i <= n; ++ i) if (g[i].size() == 1) tot ++;
    int minn = INF;
    for (int u = 1; u <= n; ++ u) {
        int res{};
        for (int v : g[u]) {
            int com{}, lv{};
            if (fa[v] == u) {
                com = siz[v];
                lv = lea[v];
            } else {
                com = n - siz[u];
                lv = tot - lea[u];
            }
            if (com > 1) res += lv;
        }
        minn = min(minn, res);
    }
    cout << minn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}