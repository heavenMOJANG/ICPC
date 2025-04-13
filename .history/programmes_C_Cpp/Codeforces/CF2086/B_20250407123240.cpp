#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n + 1, 0);
    for(int i = 0; i < n; i ++) cin >> a[i], a[i] += a[i - 1];
    int t = x / a[n - 1], r = x % a[n - 1];
    int p = lower_bound(a.begin(), a.end(), r) - a.begin();
    cout << (k - 1 - t) * n + n - p << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}