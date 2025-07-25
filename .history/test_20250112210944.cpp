#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define i128 __int128
using namespace std;
constexpr int INF = 0x7fffffff;
i128 fastPow(i128 a, int x) {
    __int128 res = 1;
    while (x) {
        if (x & 1) res = res * a;
        a *= a;
        x >>= 1;
    }
    return res;
}
i128 iabs(i128 x) { return x >= 0 ? x : -x; }
void solve() {
    int a, k; cin >> a >> k;
    __int128 n = a;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (fastPow(mid, k) >= n) r = mid;
        else l = mid + 1;
    }
    int ll = max(1ll, r - 1);
    int minn = iabs(n - fastPow(ll, k));
    if (iabs(n - fastPow(l, k)) < minn) cout << r << "\n";
    else cout << ll << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}