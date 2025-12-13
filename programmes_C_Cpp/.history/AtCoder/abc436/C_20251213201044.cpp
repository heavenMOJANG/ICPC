#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    set<pair<int, int>> s;
    int ans{};
    for (int i{}; i < m; ++ i) {
        int r, c; cin >> r >> c;
        pair<int, int> a[4] = {{r, c}, {r + 1, c}, {r, c + 1}, {r + 1, c + 1}};
        int ok = 1;
        for (auto p : a) if (s.count(p) == 0) { ok = 0; break; }
        if (ok) {
            for (auto p : a) s.insert(p);
            ans ++;
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}