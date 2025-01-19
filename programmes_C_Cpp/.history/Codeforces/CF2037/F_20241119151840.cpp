#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n), x(n);
    for (auto && y : h) cin >> y;
    for (auto && y : x) cin >> y;
    auto check = [&](int d) {
        vector<int> tmp(n), v;
        for (int i = 0; i < n; ++ i) {
            tmp[i] = (h[i] + d - 1) / d;
            if (tmp[i] <= m) {
                v.emplace_back(x[i] - m + tmp[i]);
                v.emplace_back(x[i] + m - tmp[i]);
            }
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        vector<int> diff(v.size(), 0);
        for (int i = 0; i < n; ++ i)
            if (tmp[i] <= m) {
                int l = lower_bound(v.begin(), v.end(), x[i] - m + tmp[i]) - v.begin();
                int r = lower_bound(v.begin(), v.end(), x[i] + m - tmp[i]) - v.begin();
                diff[l] ++, diff[r] --;
            }
        for (int i = 1; i < diff.size(); ++ i) diff[i] += diff[i - 1];
        for (int i = 0; i < diff.size(); ++ i) if (diff[i] >= k) return 1;
        return 0;
    };
    int l = 1, r = 1e9, ans = -1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
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