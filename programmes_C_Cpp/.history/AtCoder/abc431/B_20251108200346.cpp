#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x, n; cin >> x >> n;
    vector<int> w(n), f(n, 0);
    for (int i{}; i < n; ++ i) cin >> w[i];
    int q; cin >> q;
    int tot = x;
    while (q --) {
        int p; cin >> p, p --;
        if (f[p]) {
            tot -= w[p];
            f[p] --;
        } else {
            tot += w[p];
            f[p] ++;
        }
        cout << tot << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}