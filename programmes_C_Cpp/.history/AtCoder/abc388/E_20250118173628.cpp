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
    auto check = [&](int k) {
        for (int i = 0; i < k; ++ i) if (a[i] * 2 > a[n - k + i]) return 0;
        return 1;
    };
    int l = 0, r = n / 2;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}