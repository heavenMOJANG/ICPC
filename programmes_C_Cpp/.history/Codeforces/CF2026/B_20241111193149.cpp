#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    if (n & 1) {
        int k = 1e18;
        for (int p = 0; p < n; ++ p) {
            vector<int> b;
            int res{};
            for (int i = 0; i < n; ++ i) if (i != p) b.emplace_back(a[i]);
            for (int i = 0; i < n - 1; i += 2) res = max(res, b[i + 1] - b[i]);
            k = max(k, res);
        }
        cout << k << "\n";
    } else {
        int k{};
        for (int i = 0; i < n; i += 2) k = max(k, a[i + 1] - a[i]);
        cout << k << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}