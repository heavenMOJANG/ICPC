#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> w[i];
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> dfn(n + 1), dfv(n + 1), low(n + 1);
    int idx{};
    auto dfs = [&](auto && self, int u, int fa) -> void{
        dfn[u] = ++ idx;
        dfv[idx] = u;
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }
        low[u] = idx;
    };
    dfs(dfs, 1, -1);
    vector<int> pre(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; ++ i) pre[i] = max(pre[i - 1], w[dfv[i]]);
    for (int i = n; i >= 1; -- i) suf[i] = max(suf[i + 1], w[dfv[i]]);
    int maxn{};
    for (int i = 1; i <= n; ++ i) if (max(pre[dfn[i] - 1], suf[low[i] + 1]) > w[i] && w[i] > w[maxn]) maxn = i;
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}