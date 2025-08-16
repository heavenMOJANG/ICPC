#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], pre[i] = pre[i - 1] ^ a[i];

    while (q --) {
        int l, r; cin >> l >> r;
        int d = r - l;
        if (d & (d + 1) == 0) { cout << (pre[r] ^ pre[l - 1]) << "\n"; continue; }
        int ans{}, mask = d;
        do {
            ans ^= a[l + mask];
            mask = (mask - 1) & d;
        } while (mask != d);
        cout << ans << "\n";
    }
    return 0;
}