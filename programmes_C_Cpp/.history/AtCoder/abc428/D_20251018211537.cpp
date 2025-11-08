#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;
constexpr int INF = 0x7fffffff;
int sqr(i128 x) {
    if (x <= 0) return 0;
    long double dx{x};
    int r = floor(sqrtl(dx));
    while ((i128)r * r > x) r --;
    while ((i128)(r + 1) * (i128)(r + 1) <= x) r ++;
    return r;
}
void solve() {
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}