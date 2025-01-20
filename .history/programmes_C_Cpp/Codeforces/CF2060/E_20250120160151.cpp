#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    int n;
    vector<int> f, siz;
    DSU (int len) : n(len), f(len + 1), siz(len + 1, 1) {
        
    }
}
void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<int> f[n + 1], g[n + 1];
    for (int i = 0; i < m1; ++ i) {
        int u, v; cin >> u >> v;
        f[u].emplace_back(v);
        f[v].emplace_back(u);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}