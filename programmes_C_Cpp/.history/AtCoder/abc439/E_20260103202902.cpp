#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct S{ int a, b; };
void solve() {
    int n; cin >> n;
    vector<S> h(n);
    for (int i{}; i < n; ++ i) cin >> h[i].a >> h[i].b;
    sort(h.begin(), h.end(), [](const S &x, const S &y) {
        return x.a == y.a ? x.b > y.b : x.a < y.a;
    });
    vector<int> dp;
    for (auto [a, b] : h) {
        auto p = lower_bound(dp.begin(), dp.end(), b);
        if (p == dp.end()) dp.emplace_back(b);
        else *p = b;
    }
    cout << dp.size() << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}