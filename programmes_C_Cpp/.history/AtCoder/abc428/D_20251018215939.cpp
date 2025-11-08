#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int fac[13] = {1};
int get(int x) {
    if (x == 0) return 1;
    return floor(log10(x)) + 1;
}
void solve() {
    int C, D; cin >> C >> D;
    int d = get(C), md = get(C + D);
    int ans{};
    for (int i = d; i <= md; ++ i) {
        int l = max(1LL, fac[i - 1] - C), r = min(D, fac[i] - 1);
        if (l > r) continue;
        int lo = C * fac[i] + C + l, hi = C * fac[i] + C + r;
        int minn = ceill(sqrtl(lo));
        int maxn = floorl(sqrtl(hi));
        for (int j = minn; j <= maxn; ++ j) {
            int x = j * j - (C * fac[i] + C);
            if (l <= x && x <= r) ans ++;
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