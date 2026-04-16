#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y, id; };
void solve() {
    int n; cin >> n;
    vector<Point> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i].x >> a[i].y, a[i].id = i + 1;
    int B = 10000;
    sort(a.begin(), a.end(), [&](const Point& x, const Point& y) {
        int bx = x.x / B, by = y.x / B;
        if (bx != by) return bx < by;
        if ((bx & 1) == 0) return x.y < y.y;
        else return x.y > y.y;
    });
    vector<int> b;
    for (auto [x, y, id] : a) b.emplace_back(id);
    int pos = -1;
    for (int i{}; i < n; ++ i) if (b[i] == 1) { pos = i; break; }
    for (int i{}; i < n; ++ i) cout << b[(pos + i) % n] << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}