#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) a.emplace_back(a[i]);
    vector<int> p(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++ i) p[i] = p[i - 1] + a[i];
    int d{};
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int c; cin >> c; c %= n;
            d = (d + c) % n;
        } else {
            int l, r; cin >> l >> r;
            l = (l - 1 - d + n) % n + 1;
            r = (r - 1 - d + n) % n + 1;
            if (l > r) swap(l, r);
            cout << p[r] - p[l - 1] << "\n";
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}