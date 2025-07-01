#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
vector<int> g[N];
int n, fa[N], v2[N], vis[N];
pair<int, int> a[N];
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1, node; i < n; ++ i) cin >> node >> a[node].first >> a[node].second;
    using tpi = tuple<int, int, int>;
    priority_queue<tpi> pq;
    for (auto v: g[1]) {
        pq.push({a[v].first, a[v].second, v});
    }
    int ok = 1, cnt{};
    while (!pq.empty()) {
        auto [kind, id, loc] = pq.top(); pq.pop();
        if (vis[loc]) continue;
        vis[loc] = 1;
        cout << loc << "\n";
        if (kind == 1) {
            if (v2[2 * id - 1] && v2[2 * id]) {
                for (auto v: g[loc]) pq.push({a[v].first, a[v].second, v});
            } else { ok = 0; break; }
        } else {
            v2[id] = 1;
            for (auto v: g[loc]) pq.push({a[v].first, a[v].second, v});
        }
    }
    if (!ok) cout << "NO\n" << cnt << "\n";
    else cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}