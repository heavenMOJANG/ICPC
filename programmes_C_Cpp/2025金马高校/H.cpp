#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
vector<int> g[N];
int n, v2[N], vis[N], inq[N];
pair<int, int> a[N];
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1, u; i < n; ++ i) cin >> u >> a[u].first >> a[u].second;
    deque<int> dq;
    int cnt{};
    for (auto v: g[1]) dq.push_front(v);
    int ok = 1;
    vis[1] = 1;
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        if (vis[u]) continue;
        if (a[u].first == 2) {
            vis[u] = 1;
            v2[a[u].second] = 1;
            for (auto v: g[u]) {
                dq.push_front(v);
            }
        } else {
            if (v2[2 * a[u].second - 1] && v2[2 * a[u].second]) {
                vis[u] = 1;
                cnt ++;
                for (auto v: g[u]) {
                    dq.push_front(v);
                }
            } else {
                dq.push_back(u);
                inq[u] ++;
                if (inq[u] > 10) { ok = 0; break; }
            }
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n" << cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}