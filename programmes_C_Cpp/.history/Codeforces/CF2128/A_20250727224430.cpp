#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    vector<int> dl;
    for (int i{}; i < n; ++ i) {
        if (a[i] > c) continue;
        int x = c / a[i], t = 63 - __builtin_clzll(x);
        dl.emplace_back(x);
    }
    sort(dl.begin(), dl.end());
    int cnt{};
    for (int d : dl) if (cnt <= d) cnt ++;
    cout << n - cnt << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}