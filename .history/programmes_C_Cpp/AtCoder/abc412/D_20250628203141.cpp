#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    map<pair<int, int>, int> emp;
    vector<pair<int, int>> e;
    int idx{}, cur{};
    for (int i{}; i < n; ++ i)
        for (int j = i + 1; j < n; ++ j) {
            emp[{i, j}] = idx ++;
            e.emplace_back(i, j);
        }
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v; u --, v --;
        if (u > v) swap(u, v);
        cur |= 1 << emp[{u, v}];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}