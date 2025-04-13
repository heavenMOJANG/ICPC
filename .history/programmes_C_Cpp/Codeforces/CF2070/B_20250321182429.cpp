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
    int d0{}, d1{}, ans{};
    for (int i = 0; i < n; ++ i) {
        if (x == 0) { ans += d0 > 0; break;}
        if (k <= 0) break;
        if (s[i] == 'L') x --, d0 ++, k --;
        else x ++, d0 ++, k --;
    }
    if (x == 0) {
        for (int i = 0; i < n; ++ i) {
            if (k <= 0) break;
            if (s[i] == 'L') x --, d1 ++, k --;
            else x ++, d1 ++, k --;
            if (x == 0) break;
        }
    } else { cout << ans << "\n"; return; }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}