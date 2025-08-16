#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int k = __lg(n) + 1;
    vector f(k, vector<int> (n + 1, 0));
    for (int i = 1; i < n; ++ i) f[0][i] = a[i] ^ a[i + 1];
    // for (int j{}; j < k; ++ j) {
    //     int len = 1 << (j - 1);
    //     for (int i = 1; i + (len << 1) - 1 <= n; ++ i) f[j][i] = f[j - 1][i] ^ f[j - 1][i + len];
    // }
    while (q --) {
        int l, r; cin >> l >> r;
        int d = r - l;
        int ans{}, len{};
        for (int i{}; d; i ++, d >>= 1)
            if (d & 1) ans ^= f[i][l + len], len += 1 << i;
        cout << ans << "\n";
    }
    return 0;
}