#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int m, k, h; cin >> m >> k >> h;
    auto check = [&](int x) {
        int res = 0;
        while (x >= m) {
            int q = x / m, rem = x % m;
            res += q * m;
            x = rem + q * k;
        }
        return res + x >= h;
    };
    int l = 0, r = h;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}