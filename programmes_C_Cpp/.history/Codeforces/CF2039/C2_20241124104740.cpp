#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x, m; cin >> x >> m;
    int z = m - m % x, cnt = z / x;
    if (x < z) cnt --;
    if (1 <= (x ^ z) && (x ^ z) <= m) cnt ++;
    if (1 <= x ^ (x + z) && (x ^ (x + z)) <= m)) cnt++;
    if (x <= m) cnt --;
    for (int y = 1; y <= min(x, m); ++ y) cnt += ((x ^ y) % y == 0);
    cout << cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}