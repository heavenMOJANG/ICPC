#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x, x %= m;
    int nn = n / 2;
    vector<int> l(a.begin(), a.begin() + nn);
    vector<int> r(a.begin() + nn, a.end());
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}