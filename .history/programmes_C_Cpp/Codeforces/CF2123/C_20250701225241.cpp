#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> pre(n + 2, INF), suf(n + 2, -INF);
    for (int i = 1; i <= n; ++ i) pre[i] = min(pre[i - 1], a[i]);
    for (int i = n; i; -- i) suf[i] = max(suf[i + 1], a[i]);
    vector<int> l(n + 2, 0), r(n + 2, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}