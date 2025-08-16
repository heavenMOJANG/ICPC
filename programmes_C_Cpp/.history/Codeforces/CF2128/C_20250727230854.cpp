#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> b(n);
    for (auto && x : b) cin >> x;
    int ok = 1, m = b[0];
    auto get = [&](int x) {
        for (int i = 31; ~i; -- i)
            if (x & (1ll << i)) return (1ll << i) - 1;
    };
    for (int i = 1; i < n; ++ i) {
        if (b[i] > get(m)) { ok = 0; break; }
        m = min(m, b[i]);
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}