#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y; };
void solve() {
    int n; cin >> n;
    vector<Point> p(n);
    for (auto && [x, y] : p) cin >> x >> y;
    long double minn = LLONG_MAX;
    vector<Point> v(n);
    for (int i{}; i < n; ++ i) {
        int idx{};
        for (int j{}; j < n; ++ j)
            if (i != j) v[idx ++] = {p[j].x - p[i].x, p[j].y - p[i].y};
        sort(v.begin(), v.begin() + idx, [&](const Point& a, const Point& b) { return a.x * b.y - a.y * b.x > 0; });
        for (int j = 1; j < idx; ++ j) minn = min(minn, (long double)abs(v[j].y * v[j - 1].x - v[j].x * v[j - 1].y));
    }
    cout << fixed << setprecision(3) << minn / 2.0l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}