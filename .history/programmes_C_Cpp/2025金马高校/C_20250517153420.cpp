#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y; };
void solve() {
    int n, Y, d; cin >> n >> Y >> d;
    vector<Point> p, pr;
    int c0{};
    for (int i{}; i < n; ++ i) {
        int x, y; cin >> x >> y;
        if (y < Y) continue;
        if (x < 0) p.emplace_back(x, y);
        if (x > 0) pr.emplace_back(x, y);
        if (x == 0) c0 ++;
    }
    sort(p.begin(), p.end(), [&](const Point&a, const Point&b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });
    sort(pr.begin(), pr.end(), [&](const Point&a, const Point&b) {
        return a.x == b.x ? a.y > b.y : a.x < b.x;
    });
    for (auto [x, y]: pr) p.emplace_back(x, y);
    int n = p.size();
    for (int l{}, r{}; l < n; ++ l) {
        double dl = p[l].x * 1.0 * Y / p[l].y;
        while (r + 1 < n) {
            double dr = p[r + 1].x * 1.0 * Y / p[r + 1].y;
            if (dr - dl <= d) r ++;
            else break;
        }
        
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