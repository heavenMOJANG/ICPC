#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    int maxn = 0;
    for (int i = 0; i < n; ++ i) cin >> a[i], maxn = max(maxn, a[i]);
    for (int i = 0; i < n; ++ i) cin >> b[i], c[i] = a[i] / b[i];
    auto check = [&](int x) {
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            if (a[i] <= x) continue;
            if (a[i] - c[i] * b[i] > x) {
                res += c[i] + 1;
                continue;
            }
            res += (a[i] - x + b[i] - 1) / b[i];
        }
        return res > k;
    };
    int l = 0, r = maxn;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        if (a[i] <= l) continue;
        if (a[i] - c[i] * b[i] > l) {
            k -= c[i] + 1;
            ans += (a[i] + a[i] - b[i] * (c[i] - 1)) * c[i] / 2;
            ans += a[i] - c[i] * b[i];
            a[i] = 0;
            continue;
        }
        int t = (a[i] - l + b[i] - 1) / b[i];
        k -= t;
        ans += (a[i] + a[i] - b[i] * (t - 1)) * t / 2;
        a[i] -= b[i] * t;
    }
    if (k) {
        maxn = 0;
        for (int i = 0; i < n; ++ i) maxn = max(maxn, a[i]);
        for (int i = 0; i < n; ++ i) {
            if (k == 0) break;
            if (a[i] == maxn) {
                ans += a[i];
                k --;
            }
        }
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