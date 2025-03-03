#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int M = 5e5 + 10;
unordered_set<pair<int, int>> s;
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        int u, v; cin >> u >> v;
        if (u == v) continue;
        if (u > v) swap(u, v);
        s.insert({u, v});
    }
    cout << m - s.size() << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}