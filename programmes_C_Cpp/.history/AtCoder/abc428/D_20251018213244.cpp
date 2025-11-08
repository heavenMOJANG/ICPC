#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;
constexpr int INF = 0x7fffffff;
int fac[13] = {1};
int sqr(i128 x) {
    if (x <= 0) return 0;
    long double dx{x};
    int r = floor(sqrtl(dx));
    while ((i128)r * r > x) r --;
    while ((i128)(r + 1) * (i128)(r + 1) <= x) r ++;
    return r;
}
int get(int x) {
    if (x == 0) return 1;
    int d = 0;
    while (x) { x /= 10; d ++; }
    return d;
}
void solve() {
    int C, D; cin >> C >> D;
    int ans{}, k = get(C + D);
    for (int i = 1; i <= k; ++ i) {
        int a = fac[i - 1] - C, b = fac[i] - 1 - C;
        int L = max(1ll, a), R = min(D, b);
        if (L > R) continue;
        int A = (i128)C * (fac[i] + 1), lo = A + L, hi = A + R;
        int minn = sqr(lo), maxn = sqr(hi);
        if ((i128)minn * minn < lo) minn ++;
        if (minn > maxn) continue;
        for (int j = minn; j <= maxn; ++ j) {
            i128 n = (i128)j * j, d = n - A;
            if (d < 1) continue;
            if (d > D) continue;
            ans ++;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (int i = 1; i <= 12; ++ i) fac[i] = fac[i - 1] * 10;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}