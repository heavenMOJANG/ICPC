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
        a[u][v] ++;
        a[v][u] ++;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}