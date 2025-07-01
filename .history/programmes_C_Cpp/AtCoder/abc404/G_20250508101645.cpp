#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> l(m), r(m), s(m);
    for (int i{}; i < m; ++ i) cin >> l[i] >> r[i] >> s[i];
    vector<array<int, 3>> g;
    for (int i = 1; i <= n; ++ i) g.emplace_back(i, i - 1, -1);
    for (int i{}; i < m; ++ i) g.emplace_back(r[i], l[i] - 1, -s[i]), g.emplace_back(l[i] - 1, r[i], s[i]);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}