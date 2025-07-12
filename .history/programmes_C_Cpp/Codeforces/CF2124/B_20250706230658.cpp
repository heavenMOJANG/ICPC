#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (auto && x : a) cin >> x;
    vector<int> pre(n), suf(n + 1, 0);
    pre[0] = a[0];
    for (int i = 1; i < n; ++ i) pre[i] = min(pre[i - 1], a[i]);
    for (int i = n - 1; ~i; -- i) suf[i] = suf[i + 1] + pre[i];
    int tot = suf[0], pos = n;
    for (int i = 1; i < n; ++ i) if (pre[i] == pre[i - 1]) { pos = i; break; }
    int max0 = pos < n ? suf[pos] : 0ll, max1{};
    for (int i = 1; i < pos; ++ i) max1 = max(max1, suf[i] - a[i]);
    cout << tot - max(max0, max1) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}