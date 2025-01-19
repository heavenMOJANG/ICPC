#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1], dep(n + 1, 1), cnt(n + 1, 0);
    for (int i = 1, u, v; i <= m; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    queue<int> q;
    q.push(1);
    cnt[1] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if (cnt[1] > 10) break;
        for (auto v : g[u]) {
            if (v == 1) {
                if (dep[v] == 1) dep[v] = dep[u] + 1;
                else dep[v] = min(dep[v], dep[u] + 1);
            } else dep[v] = min(dep[v], dep[u] + 1);
            q.push(v);
            cnt[v] ++;
        }
    }
    if (cnt[1] == 1) cout << "-1\n";
    else cout << dep[1] - 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}