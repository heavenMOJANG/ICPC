#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
    int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        fa[x] = y;
    }
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<pair<int, int>> b;
    for (int i = 1; i <= n; ++ i) b.emplace_back(a[i], i);
    sort(b.begin(), b.end());
    vector<int> p(n + 1);
    for (int i{}; i < n; ++ i) p[b[i].second] = i;
    DSU dsu(n + 1);
    vector<int> vis(n + 1, 0), dis(n + 1, INF);
    vis[1] = 1, dis[1] = 0;
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int lmt = a[u] * 2;
        int pos = upper_bound(b.begin(), b.end(), make_pair(lmt, INF)) - b.begin();
        for (int i = dsu.findSet(0); i < pos; i = dsu.findSet(i)) {
            int j = b[i].second;
            dsu.unionSet(i, i + 1);
            if (!vis[j]) {
                vis[j] = 1;
                dis[j] = dis[u] + 1;
                q.push(j);
            }
        }
    }
    if (vis[n]) cout << dis[n] + 1 << "\n";
    else cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}