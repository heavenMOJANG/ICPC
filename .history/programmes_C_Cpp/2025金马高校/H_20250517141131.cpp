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
int v0[N], v1[N], vis[N];
pair<int, int> a[N];
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1, node; i < n; ++ i)
        cin >> node >> a[node].first >> a[node].second;
    deque<int> dq;
    dq.push_front(1);
    int ok = 1;
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        if (a[u].first == 1) {
            
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}