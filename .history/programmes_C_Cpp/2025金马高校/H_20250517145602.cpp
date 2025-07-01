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
    for (int i = 1, node; i < n; ++ i) cin >> node >> a[node].first >> a[node].second;
    deque<int> dq;
    int cnt2{}, cnt{};
    for (auto v: g[1]) {
        dq.push_front(v);
        if (a[v].first == 2) cnt2 ++;
    }
    int ok = 1;
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        if (vis[u]) continue;
        if (a[u].first == 2) {
            cnt2 --;
            vis[u] = 1;
            v2[a[u].second] = 1;
            for (auto v: g[u]) {
                dq.push_front(v);
                if (a[v].first == 2) cnt2 ++;
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