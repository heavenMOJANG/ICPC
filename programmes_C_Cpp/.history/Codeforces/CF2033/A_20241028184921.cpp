#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int x{}, d = 1;
    for (int i = 1; i <= n; ++ i) {
        x += (d ? -1ll : 1ll) * (2 * i - 1);
        if (abs(x) > n) {cout << i - 1 << "\n"; break;}
        d ^= 1;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}