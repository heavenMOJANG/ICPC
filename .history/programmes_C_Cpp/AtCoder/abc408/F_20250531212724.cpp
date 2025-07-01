#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, d, r; cin >> n >> d >> r;
    vector<int> h(n + !), p(n + 1);
    for (int i{}; i < n; ++ i) {
        cin >> h[i];
        p[h[i]] = i;
    }
    set<int> s;
    vector<int> t, g[n + 1];
    for (int i = n; i; -- i) {
        int u = p[i];
        if (u + d <= n) {
            int v = p[u + d];
            t.emplace_back(v);
        }
        auto L = s.lower_bound(max(0ll, u - r));
        auto R = s.upper_bound(min(n - 1, u + r));
        for (auto v = L; v != R; ++ v) g[u].emplace_back(*v);
        for (auto v: t) s.insert(v);
        t.clear();
    }
    vector<int> dis(n + 1, -1);
    function<int(int)> dfs = [&](int u) {
        if (dis[u] != -1) return dis[u];
        int dep{};
        for (auto v: g[u]) dep = max(dep, dfs(v) + 1);
        return dis[u] = dep;
    };
    int ans{};
    for (int i{}; i < n; ++ i) ans = max(ans, dfs(i));
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}