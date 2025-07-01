#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
vector<int> g[N], h[N];
int n, fa[N], v2[N], vis[N], ind[N];
pair<int, int> a[N];
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    queue<int> q;
    set<int> s;
    for (auto v: g[1])
        if (a[v].first == 1) q.push(v);
        else {
            vis[v] = 1;
            s.insert(v);
        }
    int cnt{};
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        v2[a[u].second] = 1;
        if (a[u].second & 1) {
            if (v2[a[u].second + 1]) {
                int v = a[u].second + 1 >> 1;
                if (s.find(v) != s.end() && !vis[v]) {
                    for (auto w: g[v]) {
                        if (a[w].first == 1) q.push(w);
                        else {
                            if (!vis[w]) s.insert(w);
                            vis[w] = 1;
                        }
                    }
                }
            }
        } else {

        }
    }
    if (s.size()) cout <<
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}