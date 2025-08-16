#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    if (n == 2) {
        if (!k) cout << abs(a[0] - b[0]) + abs(a[1] - b[1]) << "\n";
        else {
            vector<int> c{a[0], a[1], b[0], b[1]};
            sort(c.begin(), c.end());
            cout << abs(c[1] - c[0]) + abs(c[3] - c[2]) << "\n";
        }
        return;
    }
    int ans{};
    for (int i{}; i < n; ++ i) ans += abs(a[i] - b[i]);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}