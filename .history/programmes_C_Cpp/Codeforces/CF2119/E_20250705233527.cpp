#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n + 1);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    vector<int> r(n, 0);
    for (int i{}; i < n; ++ i) {
        if (i) r[i] |= a[i - 1];
        if (i < n - 1) r[i] |= a[i];
    }
    vector<int> c(n, 0);
    int ans{};
    auto get = [&](int x, int y) {
        int res{}, flag = 1;
        for (int i = 28; ~i; -- i) {
            int xb = (x >> i) & 1, yb = (y >> i) & 1;
            if (yb) {
                res |= 1ll << i;
                if (flag && !xb) flag = 0;
            } else {
                if (flag && xb) res |= 1ll << i;
            }
        }
        return res;
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}