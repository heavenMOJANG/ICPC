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
    int d{};
    vector<pair<int, int>> seg(n);
    for (int i{}; i < n; ++ i) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        seg[i] = {a[i], b[i]};
        d += b[i] - a[i];
    }
    sort(seg.begin(), seg.end());
    multiset<int> s;
    int minn = LLONG_MAX;
    for (auto [fi, se] : seg) {
        auto it = s.upper_bound(fi);
        if (it != s.begin()) {
            it --;
            minn = min(minn, fi - *it);
        }
        s.insert(se);
    }
    int val{};
    if (minn != LLONG_MAX) val = minn * 2;
    cout << d + val << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}