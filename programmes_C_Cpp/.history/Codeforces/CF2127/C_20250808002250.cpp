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
        d += abs(a[i] - b[i]);
        seg[i] = {min(a[i], b[i]), max(a[i], b[i])};
    }
    sort(seg.begin(), seg.end());
    vector<pair<int, int>> comp;
    comp.emplace_back(seg[0]);
    for (int i = 1; i < n; ++ i)
        if (seg[i].first <= comp.back().second)
            comp.back().second = max(comp.back().second, seg[i].second);
        else comp.emplace_back(seg[i]);
    int m = comp.size();
    int need = max(0ll, m - n + k), cost{};
    if (need > 0 && m > 1) {
        vector<int> g;
        for (int i{}; i < m - 1; ++ i) g.emplace_back(comp[i + 1].first - comp[i].second);
        sort(g.begin(), g.end());
        cost = 2 * accumulate(g.begin(), g.begin() + need, 0ll);
    }
    cout << d + cost << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}