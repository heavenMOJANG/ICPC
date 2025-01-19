#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto && [x, y] : a) cin >> x >> y;
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    for (auto [x, y] : a)
        if ((sx - x) * (sx - x) + (sy - y) * (sy - y) >= (tx - x) * (tx - x) + (ty - y) * (ty - y)) {cout << "NO\n"; return;}
    cout << "YES\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}