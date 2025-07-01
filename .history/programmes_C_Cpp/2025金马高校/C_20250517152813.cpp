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
    vector<Point> pl, pr;
    int c0{};
    for (int i{}; i < n; ++ i) {
        int x, y; cin >> x >> y;
        if (y < Y) continue;
        if (x < 0) pl.emplace_back(x, y);
        if (x > 0) pr.emplace_back(x, y);
        if (x == 0) c0 ++;
    }
    sort(pl.begin(), pl.end(), [&](const Point&a, const Point&b) {

    });
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}