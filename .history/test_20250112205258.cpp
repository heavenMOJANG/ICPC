#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
__int128 fastPow(__int128 a, int x) {
    __int128 res = 1;
    while (x) {
        if (x & 1) res = res * a;
        a *= a;
        x >>= 1;
    }
    return res;
}
__int128 iabs(__int128 x) { return x > 0 ? x : -x; }
void solve() {
    int a, k; cin >> a >> k;
    __int128 n = a;
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l >> 1);
        __int128 t = fastPow(mid, k);
        if (t < n) l = mid + 1;
        else r = mid - 1;
    }
    int minn = iabs(n - fastPow(l, k));
    int ll = max(1ll, l - 1), lr = l + 1, lll = max(1ll, ll - 1), lrr = lr + 1;
    if (iabs(n - fastPow(ll, k)) < minn) {
        minn = iabs(n - fastPow(ll, k));
        l = ll;
    }
    if (iabs(n - fastPow(lr, k)) < minn) {
        minn = iabs(n - fastPow(lr, k));
        l = lr;
    }
    if (iabs(n - fastPow(lll, k)) < minn) {
        minn = iabs(n - fastPow(lll, k));
        l = lll;
    }
    if (iabs(n - fastPow(lrr, k)) < minn) {
        minn = iabs(n - fastPow(lrr, k));
        l = lrr;
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