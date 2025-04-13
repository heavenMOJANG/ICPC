#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), fa(n + 1), siz(n + 1, 1);
    iota()
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (i - a[i] >= 1) {
            g[i].emplace_back(i - a[i]);
            g[i - a[i]].emplace_back(i);
        }
        if (i + a[i] <= n) {
            g[i].emplace_back(i + a[i]);
            g[i + a[i]].emplace_back(i);
        }
    }

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}