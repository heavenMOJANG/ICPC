#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    double a11 = y2 - y1, a12 = x2 - x1, a21 = y4 - y3, a22 = x4 - x3;
    double b1 = (y2 - y1) * x1 - (x2 - x1) * y1;
    double b2 = (y4 - y3) * x3 - (x4 - x3) * y3;
    double x = (b1 * a22 - b2 * a12) / (a11 * a22 - a12 * a21), y = (a11 * b2 - a21 * b1) / (a11 * a22 - a12 * a21);
    cout << x << endl << y << endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}