#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
vector<int> g[N];
int n, fa[N];
int v1[N], v2[N];
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
    for (auto v: g[1]) pq.push({a[v].second, a[v].first, v});
    int ok = 1, cnt{};
    while (!pq.empty()) {
        auto [kind, id, loc] = pq.top(); pq.pop();
        if (a[u].first == 1) {
            if (v1[u]) { ok = 0; break; }
            else {
                v1[u] = 1;
                if (v2[2 * a[u].second - 1] && v2[2 * a[u].second]) {
                    cnt ++;
                    for (auto v: g[u]) if (!v1[v] && !v2[v]) dq.push_front(v);
                } else dq.push_back(u);
            }
        } else {
            v2[a[u].second] = 1;
            for (auto v: g[u]) if (!v1[v] && !v2[v]) dq.push_front(v);
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