#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    int ans = n + m << 1;
    if (n > 1 && m > 1) ans -= 4;
    if (a == 1 || a == n) {
        if (b != 1 && b != m) ans += n - 2;
    } else {
        if (b == 1 || b == m) ans += m - 2;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}