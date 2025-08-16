#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    struct SEG { int l, r; };
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    int d{};
    vector<SEG> seg(n);
    for (int i{}; i < n; ++ i) {
        d += abs(a[i] - b[i]);
        seg[i] = {min(a[i], b[i]), max(a[i], b[i])};
    }
    sort(seg.begin(), seg.end(), [](const SEG& x, const SEG& y) {
        return x.l == y.l ? x.r < y.r : x.l < y.l;
    });
    vector<SEG> c;
    c.emplace_back(seg[0]);
    for (int i = 1; i < n; ++ i) {
        auto& lst = c.back();
        const SEG& cur = seg[i];
        if (cur.l <= lst.r) lst.r = max(lst.r, cur.r);
        else c.emplace_back(cur);
    }
    int m = c.size();
    int free = n - m, cost = k - free, add{};
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}