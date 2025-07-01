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
    queue <> q;
    set<int> s;
    for (auto v: g[1]) {

    }
    int ok = 1, cnt{};
    while (!q.empty()) {
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