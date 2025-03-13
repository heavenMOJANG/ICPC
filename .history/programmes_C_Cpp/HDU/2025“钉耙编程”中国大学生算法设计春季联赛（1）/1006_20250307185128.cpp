#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        vector<pair<int, int>> a;
        a.emplace_back(abs(u), u);
        a.emplace_back(abs(v), v);
        a.emplace_back(abs(w), w);
        sort(a.begin(), a.end());
        x = abs((a[2].second - a[1].second) / a[0].first);
    }
    cout << x << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}