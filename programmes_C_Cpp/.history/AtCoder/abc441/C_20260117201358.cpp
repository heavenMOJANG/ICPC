#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i <= n; ++ i) a[i] += a[i - 1];
    int ans = -1;
    for (int i = 1; i <= n; ++ i) {
        int p = max(0ll, k - n + i);
        if (!p) continue;
        int d = a[i] - a[i - p];
        if (d >= x) { ans = i; break; }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}