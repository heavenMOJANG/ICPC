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
    int ans{};
    for (int k = 1; k <= 12; ++ k) {
        int lo = fac[k - 1] - C, l = max(1ll, lo);
        int hi = fac[k] - 1 - C;
        if (hi < 1) continue;
        int r = min(D, hi);
        if (l < r) continue;
        i128 A = (i128)C * (fac[k] + 1);
        i128 a = A + l, b = A + r;
        ()
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (int i = 1; i <= 12; ++ i) f[i] = f[i - 1] * 10;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}