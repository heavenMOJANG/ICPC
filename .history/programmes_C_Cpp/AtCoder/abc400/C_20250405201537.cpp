#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int ans{};
    for (int i = 1; i < 64; ++ i) {
        int b = 1ll << i;
        if (n < b) continue;
        int k2 = n / b;
        int k = sqrt(k2);
        ans += k;
        if (i % 2 == 0) {
            for (int j = 2; (1ll << j) < b; j += 2) {
                if (b * (1ll << j) <= n) ans --;
            }
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}