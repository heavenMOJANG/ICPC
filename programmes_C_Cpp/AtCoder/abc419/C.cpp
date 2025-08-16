#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> r(n), c(n);
    for (int i{}; i < n; ++ i) cin >> r[i] >> c[i];
    auto check = [&](int x) {
        int rl = 1, rh = 1e9;
        int cl = 1, ch = 1e9;
        for (int i{}; i < n; ++ i) {
            int rd = max(1ll, r[i] - x);
            int ru = min(1000000000ll, r[i] + x);
            int cd = max(1ll, c[i] - x);
            int cu = min(1000000000ll, c[i] + x);
            rl = max(rl, rd);
            rh = min(rh, ru);
            cl = max(cl, cd);
            ch = min(ch, cu);
            if (rl > rh || cl > ch) return false;
        }
        return rl <= rh && cl <= ch;
    };
    int le{}, ri = 2e9;
    while (le < ri) {
        int mid = le + ri >> 1;
        if (check(mid)) ri = mid;
        else le = mid + 1;
    }
    cout << le << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}