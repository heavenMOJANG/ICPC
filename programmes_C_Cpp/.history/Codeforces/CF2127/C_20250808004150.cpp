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
    vector<tuple<int, int, int>> comp; 
    comp.emplace_back(seg[0].first, seg[0].second, seg[0].second - seg[0].first);
    for (int i = 1; i < n; ++ i)
        if (seg[i].first <= get<1>(comp.back())) {
            get<1>(comp.back()) = max(get<1>(comp.back()), seg[i].second);
            get<2>(comp.back()) += seg[i].second - seg[i].first;
        } else comp.emplace_back(seg[i].first, seg[i].second, seg[i].second - seg[i].first);
    int m = comp.size(), need = k - n + m;
    if (need <= 0) { cout << d << "\n"; return; }
    int cost{};
    vector<int> can;
    for (int i = 0; i < m; ++i) {
        auto [start, end, sum_len] = comp[i];
        if (end - start > sum_len) can.push_back((end - start) - sum_len);
        if (i < m - 1) can.push_back(2 * (get<0>(comp[i + 1]) - get<1>(comp[i])));
    }
    sort(can.begin(), can.end());
    cost = accumulate(can.begin(), can.begin() + min((int)can.size(), need), 0ll);
    cout << d + cost << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}