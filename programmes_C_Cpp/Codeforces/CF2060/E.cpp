#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<int> fa1(n + 1), fa2(n + 1);
    function<int(vector<int>, int)> findSet = [&](vector<int> f, int x) {
        return f[x] == x ? x : f[x] = findSet(f, f[x]);
    };
    iota(fa1.begin(), fa1.end(), 0);
    iota(fa2.begin(), fa2.end(), 0);
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