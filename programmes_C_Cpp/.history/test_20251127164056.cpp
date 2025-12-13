#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int f0{}, f1{};
    for (auto && x : a) {
        cin >> x;
        if (x & 1) f1 = 1;
        else f0 = 1;
    }
    if (f0 && f1) sort(a.begin(), a.end());
    for (int i{}; i < n; ++ i) cout << a[i] << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}