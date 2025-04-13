#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if (i) a[i] += a[i - 1];
    }
    int t = x / a[n - 1], r = x % a[n - 1];
    if (t >= k) { cout << "0\n"; return; }
    int p = lower_bound(a.begin(), a.end(), r) - a.begin();
    if (p == n) { cout << "0\n"; return; }
    cout << (k - t - 1) * n + p << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}