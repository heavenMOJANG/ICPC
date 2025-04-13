#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    int maxn = LLONG_MAX;
    if (n / (m + 1) >= k) maxn = n / (m + 1) - 1;
    maxn = min(maxn, n - m * k - 1);
    for (int i{}; i < n; ++ i) cout << i % (max(maxn + 1, k)) << " ";
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}