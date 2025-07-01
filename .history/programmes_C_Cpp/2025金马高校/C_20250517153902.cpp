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
    if (c0) p.emplace_back(0, 0);
    for (auto [x, y]: pr) p.emplace_back(x, y);
    int n = p.size(), ans{};
    for (int l{}, r{}; l < n; ++ l) {
        double dl;
        if (p[l].x == 0) dl = 0;
        else dl = p[l].x * 1.0 * Y / p[l].y;
        while (r + 1 < n) {
            double dr;
            if (p[r + 1].x == 0) dr = 0;
            else dr = p[r + 1].x * 1.0 * Y / p[r + 1].y;
            if (dr - dl <= d) r ++;
            else break;
        }
        double dr ;
        if (p[r].x == 0) dr = 0;
        else dr = p[r].x * 1.0 * Y / p[r].y;
        int res = r - l + 1;
        if (p[l].x <= 0 && 0 <= p[r].x) res += c0 - 1;
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