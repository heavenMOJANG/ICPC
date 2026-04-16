#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int L, R, D, U; cin >> L >> R >> D >> U;
    auto cal = [](int l, int r) {
        if (l & 1) l ++;
        if (r & 1) r --;
        if (l > r) return 0ll;
        return (r - l) / 2 + 1;
    };
    int pre = cal(D, U), ans{};
    for (int i = L; i <= R; ++ i) {
        int x = abs(i);
        int l = max(D, -x), r = min(U, x);
        if (x & 1) ans += pre - cal(l, r);
        else ans += pre + (l <= r ? (r - l + 1) - cal(l, r) : 0ll);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}