#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int N = 2e5 + 10;
int fac[N];
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> clr(n + 1, -1); clr[1] = 0;
    queue<int> q; q.push(1);
    bool ok = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (clr[v] == -1) {
                clr[v] = clr[u] ^ 1;
                q.push(v);
            } else if (clr[v] == clr[u]) ok = 0;
        }
    }
    if (!ok) { cout << "0\n"; return; }
    for (int i = 1; i <= n; ++ i) sort(g[i].begin(), g[i].end());
    map<vector<int>, vector<int>> mp;
    for (int i = 1; i <= n; ++ i) mp[g[i]].emplace_back(i);
    int cnt = 0;
    for (auto const& [key, nodes] : mp) {
        if (nodes.empty()) continue;
        int u = nodes[0];
        set<vector<int>> ad;
        for (int v : g[u]) ad.insert(g[v]);
        int d = ad.size();
        if (d > 2) { cout << "0\n"; return; }
        if (d == 1) cnt ++;
    }
    if (cnt != 2) { cout << "0\n"; return; }
    int res = 1;
    for (auto const& [key, nodes] : mp) res = res * fac[nodes.size()] % MOD;
    int ans = 0;
    if (mp.size() > 2) ans = res * 4 % MOD;
    else ans = res * 2 % MOD;
    cout << ans << "\n";
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}