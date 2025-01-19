#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> g[n + 1];
    for (int i = 2, j; i <= n; ++ i) cin >> j, g[j].emplace_back(i);
    vector<int> a(n + 1), dep(n + 1, 0);
    vector fa(n, vector<int>(20, 0));
    function <void(int, int)> dfs = [&](int u, int f) {
        dep[u] = dep[f] + 1;
        fa[u][0] = f;
        for (int i = 0; i < 20; ++ i)
    };
    for (int i = 1; i <= n; ++ i) cin >> a[i];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}