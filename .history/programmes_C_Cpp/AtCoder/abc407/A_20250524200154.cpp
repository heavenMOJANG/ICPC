#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b; cin >> a >> b;
    int l = a / b, r = a / b + 1;
    if (abs(l * 1.0 - a * 1.0 / b) <= abs(r * 1.0 - a * 1.0 / b)) cout << l;
    else cout << r;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}