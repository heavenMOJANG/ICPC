#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y; };
void solve() {
    int n, Y, d; cin >> n >> Y >> d;
    vector<Point> p;
    for (int i{}; i < n; ++ i) {
        int x, y; cin >> x >> y;
        if (y < Y) continue;
        p.emplace_back(x, y);
    }
    sort(p.begin(), p.end(), [&](const Point&a, const Point&b) { return atan2(a.y, a.x) > atan2(b.y, b.x); });
    n = p.size();
    int ans{};
    for (int l{}, r{}; l < n; ++ l) {
        double dl = p[l].x * 1.0 * Y / p[l].y;
        while (r + 1 < n) {
            double dr = p[r + 1].x * 1.0 * Y / p[r + 1].y;
            if (dr - dl <= d) r ++;
            else break;
        }
        ans = max(ans, r - l + 1);
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