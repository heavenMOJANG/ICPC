#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int id, d;
    bool operator < (const Node &b) const { return d > b.d; }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(n + 1), dis(n + 1), tmp(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> w[i];
    vector<pair<int, int>> g[n + 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}