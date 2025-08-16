#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    int d{};
    for (int i = 0; i < n; ++ i) d += abs(a[i] - b[i]);
    if (!k) { cout << d << "\n"; return; }
    if (n == 2) {
        vector<int> c{a[0], a[1], b[0], b[1]};
        sort(c.begin(), c.end());
        cout << (c[3] - c[0]) + (c[2] - c[1]) << "\n";
        return;
    }
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; ++i)
        if (a[i] < b[i]) seg[i] = {a[i], b[i]};
        else seg[i] = {b[i], a[i]};
    sort(seg.begin(), seg.end());
    int minn = LLONG_MAX, maxn = seg[0].second, flag{};
    for (int i = 1; i < n; ++i) {
        int l = seg[i].first, r = seg[i].second;
        if (l < maxn) { flag = 1; break; }
        int gap = l - maxn;
        minn = min(minn, gap);
        maxn = max(maxn, r);
    }
    int inc{};
    if (!flag) inc = 2 * minn;
    cout << d + inc << "\n";
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}