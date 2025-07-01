#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    map<pair<int, int>, int> emp;
    vector<pair<int, int>> e;
    int idx{}, cur{};
    for (int i{}; i < n - 1; ++ i)
        for (int j = i + 1; j < n; ++ j) {
            emp[{i, j}] = idx ++;
            e.emplace_back(i, j);
        }
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v; u --, v --;
        if (u > v) swap(u, v);
        cur |= 1 << emp[{u, v}];
    }
    vector<int> d(8, 0), vis(28, 0);
    int ans = INF;
    function<void(int, int)> dfs = [&](int x, int ly) {
        if (ly == n) {
            ans = min(ans, (int)__builtin_popcount(cur ^ x));
            return;
        }
        int u = -1;
        for (int i{}; i < n; ++ i) if (d[i] < 2) { u = i; break; }
        vector<int> tmp;
        for (int v = u + 1; v < n; ++ v)
            if (d[v] < 2 && !vis[emp[{u, v}]]) tmp.emplace_back(v);
        for (int i{}; i < tmp.size(); ++ i)
            for (int j{}; j < tmp.size(); ++ j) {
                int e1 = emp[{u, tmp[i]}], e2 = emp[{u, tmp[j]}];
                vis[e1] = vis[e2] = 1;
                d[u] += 2, d[tmp[i]] ++, d[tmp[j]] ++;
                dfs(x | (1 << e1) | (1 << e2), ly + 2);
                vis[e1] = vis[e2] = 0;
                d[u] -= 2, d[tmp[i]] --, d[tmp[j]] --;
            }
    };
    dfs(0, 0);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}