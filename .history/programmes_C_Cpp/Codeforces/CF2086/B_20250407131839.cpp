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
    for(int i = 1; i <= n; i ++) cin >> a[i];
    reverse(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) a[i] += a[i - 1];
    int t = x / a[n], r = x % a[n];
    if (!r && t) t --;
    int p = lower_bound(a.begin() + 1, a.end(), r) - a.begin();
    cout << max(0ll, n * k - (t * n + p)) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}