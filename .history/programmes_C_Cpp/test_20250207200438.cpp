#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point {
    int x, y;
    bool operator < (const Point & b) {
        int x1 = b.x - x, y1 = b.y - y, x2 = -x, y2 = -y;
        return x1 * y2  - x2 * y1 == 0 ? x < b.x : x1 * y2  - x2 * y1 > 0;
    }
};
void solve() {
    int n, k; cin >> n >> k;
    vector<Point> a(n);
    double PI = acos(-1.0);
    for (int i = 0; i < n; ++ i) cin >> a[i].x >> a[i].y;
    if (k == n) { cout << "6.2831853072\n"; return; }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++ i) a.emplace_back(a[i]);
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << fixed << setprecision(10) << 2 * PI / l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}