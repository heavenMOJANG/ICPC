#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<pair<int, int>, int> pos;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) {
        cin >> b[i];
        pos[{a[i], b[i]}] = i;
    }
    int cnt{}, rec{};
    for (int i = 1; i < n; ++ i)
        if (a[i] == b[i] && !pos[{b[i], a[i]}]) cnt ++, rec = i;
    if (cnt > 1) { cout << "-1\n"; return; }
    vector<pair<int, int>> ans;
    auto proc = [&](int x, int y) {
        ans.emplace_back(x, y);
        swap(a[x], a[y]); swap(b[x], b[y]);
        pos[{a[x], b[x]}] = x;
        pos[{a[y], b[y]}] = y;
    };
    if (rec && rec != (n + 1) / 2) proc(rec, (n + 1) / 2);
    for (int i = 1; i <= n / 2; ++ i) if (pos[{b[i], a[i]}] != n - i + 1) proc(pos[{b[i], a[i]}], n - i + 1);
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) cout << x << " " << y << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}