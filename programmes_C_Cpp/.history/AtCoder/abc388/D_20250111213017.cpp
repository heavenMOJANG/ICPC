#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 2), diff(n + 2, 0);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        diff[i] += a[i];
        diff[i + 1] -= a[i];
    }
    for (int i = 1; i <= n; ++ i) {
        diff[i] += diff[i - 1];
        int d = min(diff[i], n - i);
        a[i] = diff[i] - d;
        diff[i + 1] += d;
        diff[i + 1 + d] -= d;
    }
    for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}