#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int maxn = *max_element(a.begin(), a.end());
    int limit = (n + m) / 2 + 1;
    int l = 1, r = maxn, ans = 1;
    auto check = [&](int x) {
        int res{}, cnt{};
        for (int y : a) {
            int k = y / x;
            res += k;
            if (k) cnt += k - 1;
        }
        int need = limit - n;
        if (need < 0) need = 0;
        return res >= limit && cnt >= need && m >= need;
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
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