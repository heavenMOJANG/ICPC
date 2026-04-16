#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y, id; };
int getDis(Point x, Point y) {
    return abs(x.x - y.x) + abs(x.y - y.y);
}
void solve() {
    int n; cin >> n;
    vector<Point> a(n);
    for (int i{}; i < n; ++ i) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
    }
    int minn = 2e18;
    vector<Point> b;
    int S = 20000000 / sqrt(n), st = max(1ll, S - 30000), en = S + 30000;
    for (int i = st; i <= en; i += 1000) {
        vector<Point> v = a;
        sort(v.begin(), v.end(), [i](const Point& x, const Point& y)) {
            int bx = x.x / i, by = y.x / i;
            if (bx != by) return bx < by;
            if (bx & 1 == 0) return x.y < y.y;
            return x.y > y.y;
        };
        int tot{};
        for (int j{}; j < n; ++ j) tot += getDis(v[j], v[(j + 1) % n]);
        if (tot < minn) { minn = tot; b = v; }
    }
    int pos = -1;
    for (int i{}; i < n; ++ i) if (b[i].id == 1) { pos = i; break; }
    for (int i{}; i < n; ++ i) cout << b[(pos + i) % n].id << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}