#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int ans{}, cnt0{}, cnt1{};
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        if (x & 1) cnt1 ++;
        else cnt0 ++;
    }
    int flag{};
    for (int i = 0; i < n; ++ i) {
        if (flag & 1) {
            if (cnt1) cnt1 --, ans ++;
            else break;
        } else {
            if (cnt0) cnt0 --, ans ++, flag = 1;
            else break;
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