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
    for (int i = d; i <= md; ++i) {
        int pow_m_minus_1 = 1;
        for (int i = 0; i < i - 1; ++i) pow_m_minus_1 *= 10;
        int pow_m = pow_m_minus_1 * 10;
        
        int x_min = max(1LL, fac[i - 1] - C);
        int x_max = min(D, fac[i] - 1);
        if (x_min > x_max) continue;
        int lo = C * fac[i] + C + x_min;
        int hi = C * fac[i] + C + x_max;

        int k_min = ceill(sqrtl(lo));
        int k_max = floorl(sqrtl(hi));
        for (int k = k_min; k <= k_max; ++k) {
            int x = k * k - (C * pow_m + C);
            if (x_min <= x && x <= x_max) ans ++;
        }
    }
    
    return ans;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (int i = 1; i <= 12; ++ i) fac[i] = fac[i - 1] * 10;
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}