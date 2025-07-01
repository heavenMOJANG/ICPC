#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, j, k; cin >> n >> j >> k;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int cnt{};
    for (int i{}; i < n; ++ i) if (a[i] > a[j - 1]) cnt ++;
    cout << (cnt <= k - 1 ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}