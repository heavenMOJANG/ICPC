#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x, k; cin >> n >> x >> k;
    string s; cin >> s;
    int d0 = n + 1, d1 = k + 1;
    for (int i{}, cur{}; i < n; ++ i) {
        if (s[i] == 'L') cur --, x --;
        else cur ++, x ++;
        if (cur == 0) if (d1 == k + 1) d1 = i + 1;
        if (x == 0) if (d0 == n + 1) d0 = i + 1;
    }
    int ans{};
    if (d0 != n + 1 && k >= d0) ans = (k - d0) / d1 + 1;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}