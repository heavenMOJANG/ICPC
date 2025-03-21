#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    if (k & 1 || n == 1) { cout << "0\n"; return; }
    int m = k / 2, r = n - 1 - m;
    if (r < 0) { cout << "0\n"; return; }
    int d = 2 * m, q = r / d;
    int ans = (q + 1) * (n - m * (q + 1));
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}