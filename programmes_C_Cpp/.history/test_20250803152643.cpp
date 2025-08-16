#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    while (q --) {
        int l, r; cin >> l >> r;
        int ans{};
        for (int msk = r - l; ; msk = (msk - 1) & (r - l)) {
            ans ^= a[l - 1 + msk];
            if (msk == 0) break;
        }
        cout << ans << "\n";
    }
    return 0;
}