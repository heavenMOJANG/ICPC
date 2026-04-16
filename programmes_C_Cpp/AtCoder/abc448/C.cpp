#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    vector<pair<int, int>> vp;
    for (int i{}; i < n; ++ i) vp.emplace_back(a[i], i + 1);
    sort(vp.begin(), vp.end());
    vector<pair<int, int>> b(vp.begin(), vp.begin() + 6);
    while (q --) {
        int k; cin >> k;
        unordered_set<int> us;
        for (int i{}; i < k; ++ i) {
            int x; cin >> x;
            us.insert(x);
        }
        for (auto [fi, se] : b)
            if (!us.count(se)) { cout << fi << "\n"; break; }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}