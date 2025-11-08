#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<int> g[n], rg[n];
    for (int i{}, u, v; i < m; ++ i) {
        cin >> u >> v, u --, v --;
        g[u].emplace_back(v);
        rg[v].emplace_back(u);
    }
    vector<int> cur(n, 0), nxt(n, 0);
    for (int i{}; i < n; ++ i) cur[i] = s[i] == 'A';
    for (int i = 1; i <= 2 * k; ++ i) {
        fill(nxt.begin(), nxt.end(), 0);
        if (i % 2 == 0)
            for (int v{}; v < n; ++ v) {
                if (!cur[v]) continue;
                for (int u : rg[v]) nxt[u] = 1;
            }
        else
            for (int u{}; u < n; ++ u) {
                int ok = 1;
                for (int v : g[u]) if (!cur[v]) { ok = 0; break; }
                nxt[u] = ok;
            }
        cur.swap(nxt);
    }
    cout << (cur[0] ? "Alice\n" : "Bob\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}