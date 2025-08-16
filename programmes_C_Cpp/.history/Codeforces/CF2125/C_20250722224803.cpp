#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l, r; cin >> l >> r;
    vector<int> p{2, 3, 5, 7};
    auto cal = [&](int x) {
        if (!x) return 0ll;
        int res{};
        for (int mask{}; mask < 16; ++ mask) {
            int tmp = 1;
            for (int i{}; i < 4; ++ i)
                if ((1 << i) & mask) {
                    tmp *= p[i];
                    if (tmp > x) break;
                }
            if (tmp > x) continue;
            int num = x / tmp;
            int y = mask, cnt{};
            while (y) {
                y = y & (y - 1);
                cnt ++;
            }
            res += cnt & 1 ? -num : num;
        }
        return res;
    };
    cout << cal(r) - cal(l - 1) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}