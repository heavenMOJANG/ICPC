#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    function<int(int, int)> dfs = [&](int s, int d) {
        if (d == 0) return a[s];
        int k = floor(log2(d)), len = 1 << k, res = d - len;
        return dfs(s, res) ^ dfs(s + len, res);
    };
    while (q --) {
        int l, r; cin >> l >> r;
        cout << dfs(l, r - l) << "\n";
    }
    return 0;
}