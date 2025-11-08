#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> e(m);
    for (int i{}, u, v; i < m; ++ i) {
        cin >> u >> v, u --, v --;
        e.emplace_back(u, v);
    }
    int maxc{};
    for (int mask{}; mask < (1ll << n); ++ mask) {
        int c{};
        for (auto [u, v] : e) {
            if (((mask >> u) & 1) != ((mask >> v) & 1)) c ++;
            maxc = max(maxc, c);
        }
    }
    cout << m - maxc << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}