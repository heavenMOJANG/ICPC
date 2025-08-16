#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    int maxA{}, sum{};
    for (auto && x : a) cin >> x, maxA = max(maxA, x), sum += x;
    vector<int> b(q);
    int maxB{};
    for (auto && x : b) cin >> x, maxB = max(maxB, x);
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}