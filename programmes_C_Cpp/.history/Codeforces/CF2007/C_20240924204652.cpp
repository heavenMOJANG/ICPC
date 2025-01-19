#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, a, b; cin >> n >> a >> b;
    int g = __gcd(a, b);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> c[i], c[i] %= g;
    n = unique(c.begin() + 1, c.begin() + 1 + n) - c.begin() - 1;
    int ans = c[n] - c[1];
    for (int i = 2; i <= n; ++ i) ans = min(ans, c[i - 1] - c[i] + g);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}