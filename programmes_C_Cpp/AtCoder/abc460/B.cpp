#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    int dx = x1 - x2, dy = y1 - y2;
    int d2 = dx * dx + dy * dy;
    int sr = r1 + r2, dr = r1 - r2;
    sr = sr * sr, dr = dr * dr;
    cout << (dr <= d2 && d2 <= sr ? "Yes" : "No") << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}
