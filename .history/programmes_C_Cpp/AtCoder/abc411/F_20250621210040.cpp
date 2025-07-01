#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/modint>
#define int long long
using namespace std;
using mint = atcoder::modint998244353;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector g(n, vector<mint>(n, 0));
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g[u][v] ++;
        g[v][u] ++;
    }
    mint ans{};
    for (int s{}; s < n; ++ s) {
        int k = n - s, ms = 1 << k;
        vector dp(ms, vector<mint>(k, 0));
        dp[1][0] = 1;
        for (int mask = 1; mask < ms; ++ mask) {
            if (!(mask & 1)) continue;
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