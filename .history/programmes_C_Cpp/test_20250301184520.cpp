#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<array<int, 4>> a;
    for (int i = 0; i < n; ++ i) {
        int x0, y0, l, h; cin >> x0 >> y0 >> l >> h;
        a.emplace_back(array<int, 4>{x0, y0, x0 + l, y0 + h});
    }
    int x, y; cin >> x >> y;
    int ans = -1;
    for (int i = 0; i < n; ++ i) {
        auto [x0, y0, x1, y1] = a[i];
        if (x >= x0 && x <= x1 && y >= y0 && y <= y1) ans = i + 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}