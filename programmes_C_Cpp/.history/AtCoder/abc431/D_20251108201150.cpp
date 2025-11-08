#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 4e18;
void solve() {
    int n; cin >> n;
    vector<int> w(n), h(n), b(n);
    int sum{};
    for (int i{}; i < n; ++ i) {
        cin >> w[i] >> h[i] >> b[i];
        sum += b[i];
    }
    int v = accumulate(w.begin(), w.end(), 0ll) / 2;
    vector<int> dp(v + 10, -INF);

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}