#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int m, k, h; cin >> m >> k >> h;
    if (m == k) {cout << h << "\n"; return;}
    auto check = [&](int x) {
        if (x < m) return x >= h;
        int res = 0, tmp = x;
        int a = (x - m) / (m - k);
        res = x + a * k;
        return res >= h;
    };
    int l = 0, r = h;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}