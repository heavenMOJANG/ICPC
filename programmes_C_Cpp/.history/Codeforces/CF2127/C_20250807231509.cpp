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
    vector<int> g;
    int cur = seg[0].second, cnt = 1;
    for (int i = 1; i < n; ++ i) {
        if (seg[i].first > cur) {
            g.emplace_back(seg[i].first - cur);
            cnt ++;
        }
        cur = max(cur, seg[i].second);
    }
    int tot = n - cnt, val{};
    if (k > tot) {
        sort(g.begin(), g.end());
        for (int i{}; i < min(k - tot, (int)g.size()); ++ i) val += g[i] * 2;
    }
    cout << d + val << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}