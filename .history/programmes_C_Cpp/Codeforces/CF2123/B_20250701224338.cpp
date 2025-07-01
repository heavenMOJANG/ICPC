#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, j, k; cin >> n >> j >> k;
    vector<int> a(n);
    int maxn{};
    for (auto && x : a) cin >> x, maxn = max(maxn, x);
    if (k == 1) {
        cout << (a[j - 1] == maxn ? "YES\n" : "NO\n");
    } else cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}