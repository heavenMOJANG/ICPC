#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> w(n), dfn(n), low(n);
    for (auto && x : w) cin >> x;
    int idx{};
    auto dfs = [&](auto && self, int u, int fa) {
        dfn[u] = ++ idx;
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }
        low[u] = idx;
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}