#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end());
    int ans{};
    for (int i{}; i < n; ++ i) {
        if (a[i] > c) ans ++;
        for (int j = i + 1; j < n; ++ j) a[j] *= 2;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}