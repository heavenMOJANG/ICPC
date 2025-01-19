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
        if (2 * a + 1 > n) break;
        for (int b = 1; b <= x - a - 1; ++ b) {
            if (a * b + a + b > n) break;
            int c = min((n - a * b) / (a + b), x - a - b);
            ans += c;
        }
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