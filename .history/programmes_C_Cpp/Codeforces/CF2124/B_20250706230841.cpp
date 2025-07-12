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
    int ans = pre[n];
    vector<int> p(n + 1, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}