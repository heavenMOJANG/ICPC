#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> prem(n + 1), pre(n + 1);
    prem[1] = pre[1] = a[1];
    for (int i = 2; i <= n; ++ i) {
        prem[i] = min(prem[i - 1], a[i]);
        pre[i] = pre[i] + a[i];
    }
    vector<int> p(n + 1, 0);
    for (int i = 2; i <= n; ++ i)
        if (a[i] >= prem[i - 1]) p[i] = p[i - 1] | 1;
    int ans = pre[n];
    for (int i = 2; i <= n; ++ i) {
        if (p[i - 1]) ans = min(ans, pre[i - 1]);
        ans = min(ans, pre[i - 1] + a[i]);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}