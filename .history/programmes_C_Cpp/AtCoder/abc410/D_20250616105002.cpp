#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    map<pair<int, int>, vector<pair<int, int>>> g;
    for (int i{}; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        for (int s{}; s < 1024; ++ s) g[{u, s}].emplace_back(v, s ^ w);
    }
    vector dis(1025, vector<int> (1024, INF));
    queue<pair<int, int>>;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}