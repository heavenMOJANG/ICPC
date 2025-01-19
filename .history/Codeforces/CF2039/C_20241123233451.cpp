#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x, m; cin >> x >> m;
    int cnt{};
    for (int y = 1; y <= min(m, 2 * x); ++ y) {
        if (x == y) { cnt ++; continue; }
        int z = x ^ y;
        if (x % z == 0 || y % z == 0) cnt ++;
    }
    cout << cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}