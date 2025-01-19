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
void solve() {
    int a, k; cin >> a >> k;
    __int128 n = a;
    int l = 1, r = n;
    __int128 d = fastPow(n, k);
    while (l < r) {
        int mid = l + r >> 1;
        __int128 t = fastPow(mid, k);
        __int128 dd = n > t ? n - t : t - n;
        if (dd < d) {
            d = dd;
            r = mid;
        } else l = mid + 1;
    }
    int ll = max(1ll, l - 1), lr = l + 1;
    
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}