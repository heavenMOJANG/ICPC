#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a == b) { cout << "0\n"; return; }
    if (a > b) {
        if (a - b == 1 && (a & 1)) cout << y << "\n";
        else cout << "-1\n";
        return;
    }
    int d = b - a;
    int da = a & 1 ? a + 1 : a;
    int db = (b - 1) & 1 ? b - 2 : b - 1;
    int q = da > db ? 0ll : (db - da) / 2 + 1;
    cout << q * min(x, y) + (d - q) * x << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}