#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1], dep(n + 1, 1);
    int rt;
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x;
        if (x == -1) rt = i;
        else g[x].emplace_back(i);
    }
    function<void(int)> dfs = [&](int u) {
        for (auto v : g[u]) {
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    };
    int maxn = *max_element(dep.begin() + 1, dep.end());
    for (int i = 1; i <= n; ++ i) if (dep[i] == maxn) ans.emplace_back(i);
    vector<int> ans;
    for (int i = 1; i <= n; ++ i)
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}