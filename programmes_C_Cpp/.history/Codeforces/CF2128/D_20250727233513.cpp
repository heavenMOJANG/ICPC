#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto && x : p) cin >> x;
    int ans = n * (n + 1) * (n + 2) / 6;
    for (int i{}; i < n - 1; ++ i)
        if (p[i] < p[i + 1]) ans -= (i + 1) * (n - i - 1);
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}