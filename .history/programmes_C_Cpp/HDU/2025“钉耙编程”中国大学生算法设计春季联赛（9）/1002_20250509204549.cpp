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
    for (auto && x : a) cin >> x;
    vector<int> b(n - 1);
    for (int i{}; i < n - 1; ++ i) b[i] = a[i + 1] - a[i];
    vector<int> odd(n - 1), even(n - 1);
    {
        int l{}, r = -1;
        for (int i{}; i < n - 1; ++ i) {
            int k = (i > r ? 1ll : min(odd[l + r - i], r - i + 1));
            while (i - k >= 0 && i + k < n - 1 && b[i - k] == -b[i + k]) k ++;
            odd[i] = k - 1;
            if (i + odd[i] > r) {
                l = i - odd[i];
                r = i + odd[i];
            }
        }
    }
    {
        int l{}, r = -1;
        for (int i{}; i < n - 1; ++ i) {
            int k = (i > r ? 0ll : min(even[l + r - i + 1], r - i + 1));
            while (i - k >= 0 && i + k + 1 < n - 1 && b[i - k] == -b[i + k + 1]) k ++;
            even[i] = k;
            if (i + even[i] > r) {
                l = i - even[i] + 1;
                r = i + even[i];
            }
        }
    }
    int ans = n;
    for (int i{}; i < n - 1; ++ i) ans += odd[i] + even[i];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}