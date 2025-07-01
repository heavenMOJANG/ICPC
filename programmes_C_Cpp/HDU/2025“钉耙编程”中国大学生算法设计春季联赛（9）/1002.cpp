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
    for (int i{}; i < n; ++ i) cin >> a[i];
    vector<int> b(n - 1);
    for (int i{}; i < n - 1; ++ i) b[i] = a[i + 1] - a[i];
    vector<int> d1(n - 1);
    for (int i = 0, l = 0, r = -1; i < n - 1; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n - 1 && b[i - k] == b[i + k]) k ++;
        d1[i] = k --;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n - 1);
    for (int i = 0, l = 0, r = -1; i < n - 1; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n - 1 && b[i - k - 1] == b[i + k]) k ++;
        d2[i] = k --;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    int ans = n;
    for (int i{}; i < n - 1; ++ i) ans += d1[i] + d2[i];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}