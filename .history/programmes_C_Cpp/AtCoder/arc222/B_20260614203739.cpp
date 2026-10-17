#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    int ans{};
    if (a >= b + c) ans = max(ans, c + max(0ll, b - 1));
    if (b >= c + a) ans = max(ans, a + max(0ll, c - 1));
    if (c >= a + b) ans = max(ans, b + max(0ll, a - 1));
    if (!ans)
        ans = a + b + c & 1 ? (a + b + c - 3) / 2 : (a + b + c - 4) / 2;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}