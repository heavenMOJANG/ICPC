#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    long double x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    x0 *= -1, y0 *= -1;
    cout << fixed << setprecision(10) << sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}