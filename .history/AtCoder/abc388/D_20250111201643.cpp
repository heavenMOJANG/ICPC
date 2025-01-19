#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int cur{};
    for (int i = 0; i < n; ++ i) {
        a[i] = max(0ll, a[i] + cur - (n - i - 1) + 1);
        if (a[i]) cur ++;
    }
    for (int i = 0; i < n; ++ i) cout << a[i] << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}