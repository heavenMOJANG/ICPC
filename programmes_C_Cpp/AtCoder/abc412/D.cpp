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
    vector<int> d(8, 0);
    int ans = INF;
    function<void(int, int, int)> dfs = [&](int x, int ly, int b) {
        if (ly == n) {
            for (int i{}; i < n; ++ i) if (d[i] != 2) return;
            ans = min(ans, (int)__builtin_popcount(cur ^ x));
            return;
        }
        if (b == n * (n - 1) / 2) return;
        auto[u, v] = e[b];
        if (d[u] < 2 && d[v] < 2) {
            d[u] ++, d[v] ++;
            dfs(x | (1 << b), ly + 1, b + 1);
            d[u] --, d[v] --;
        }
        dfs(x, ly, b + 1);
    };
    dfs(0, 0, 0);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}