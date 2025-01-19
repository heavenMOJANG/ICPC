#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int maxn = 0, minn = LLONG_MAX;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i], maxn = max(maxn, a[i]), minn = min(minn, a[i]);
    int l = minn, r = maxn, ans1 = l;
    auto check1 = [&](int x) {
        int res = 0;
        for (int i = 1; i <= n; ++ i) {
            if (a[i] > x) res += a[i] - x;
            if (a[i] < x) {
                if (x - a[i] > res) return 0;
                res -= x - a[i];
            }
        }
        return 1;
    };
    auto check2 = [&](int x) {
        int res = 0;
        for (int i = 1; i <= n; ++ i) {
            if (a[i] > x) res += a[i] - x;
            if (a[i] < x) res -= x - a[i], res = max(res, 0ll);
        }
        if (res) return 0;
        return 1;
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (check1(mid)) ans1 = mid, l = mid + 1;
        else r = mid - 1;
    }
    l = minn, r = maxn;
    int ans2 = maxn;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check2(mid)) ans2 = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans2 - ans1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}