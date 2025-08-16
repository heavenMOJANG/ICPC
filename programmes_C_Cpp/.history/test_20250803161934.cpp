#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    vector f(20, vector<int> (n + 1, 0));
    for (int i{}; i < n; ++ i) f[0][i] = a[i];
    for (int k = 1; k < 20; ++ k)
        for (int i{}; i + (1 << k) <= n; ++ i)
            f[k][i] = f[k - 1][i] ^ f[k - 1][i + (1 << (k - 1))];
    while (q --) {
        int l, r; cin >> l >> r;
        int d = r - l, ans{}, p = l - 1;
        for (int i{}; i < 20; ++ i)
            if ((d >> i) & 1) {
                if (p < n) ans ^= f[i][p];
                p += 1 << i;
            }
        cout << ans << "\n";
    }
    return 0;
}