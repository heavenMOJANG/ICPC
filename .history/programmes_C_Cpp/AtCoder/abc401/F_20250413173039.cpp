#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n1; cin >> n1;
    vector<int> g1[n1];
    for (int i = 1; i < n1; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g1[u].emplace_back(v);
        g1[v].emplace_back(u);
    }
    int n2; cin >> n2;
    vector<int> g2[n2];
    for (int i = 1; i < n2; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g2[u].emplace_back(v);
        g2[v].emplace_back(u);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}