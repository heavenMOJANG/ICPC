#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    int ans = 0;
    for (int a = 1; a <= x - 2; ++ a) {
        int l = 1, r = x - a - 1;
        while (l < r) {
            int b = l + r >> 1;
            int c = (n - a * b) / (a + b);
            if (c > 0) l = b + 1;
            else r = b;
        }
        int b = l, c = (n - a * b) / (a + b);
        if (c) ans += a * b * c;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}