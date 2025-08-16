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
    vector f(k, vector<int>(n + 1, 0));
    for (int i = 1; i < n; ++ i) f[0][i] = a[i] ^ a[i + 1];
    for (int j = 1; j < k; ++ j)
        for (int i = 1; i + (1 << j) <= n; ++ i) f[j][i] = f[j - 1][i] ^ f[j - 1][i + (1 << (j - 1))];
    while (q --) {
        int l, r; cin >> l >> r;
        int ans = a[l], d = r - l, len{};
        for (int i{}; d; i ++, d >>= 1)
            if (d & 1) {
                ans ^= f[i][l + len];
                len += 1 << i;
            }
        cout << ans << "\n";
    }
    return 0;
}