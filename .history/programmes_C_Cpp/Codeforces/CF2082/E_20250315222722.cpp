#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> g[n * k + 1], siz(n * k + 1, 1);
    for (int i = 1; i < n * k; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int ok = 1;
    function<void(int, int, int)> dfs = [&](int u, int f, int t) {
        if (!t) {
            dfs(u, f, 1);
            for (auto v : g[u]) {
                if (v == f) continue;
                dfs(v, u, 0);
            }
        } 
        int cnt{};
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(v, u);
            siz[u] += siz[v];
            if (siz[v]) cnt ++;
        }
        if (siz[u] > k || cnt >= 3) { ok = 0; return; }
        if (siz[u] < k || cnt >= 2) { ok = 0; return; }
        if (siz[u] == k) siz[u] = 0;
        return;
    };
    dfs(1, -1, 0);
    if (ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}