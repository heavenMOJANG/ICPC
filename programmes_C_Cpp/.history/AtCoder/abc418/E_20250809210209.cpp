#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i{}; i < n; ++ i) cin >> x[i] >> y[i];
    map<pair<int, int>, int> mps, mpm;
    for (int i{}; i < n - 1; ++ i)
        for (int j = i + 1; j < n; ++ j) {
            int dx = x[j] - x[i], dy = y[j] - y[i];
            int g = __gcd(dx, dy);
            dx /= g, dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) dx = -dx, dy = -dy;
            mps[{dx, dy}] ++;
            mpm[{x[i] + x[j], y[i] + y[j]}] ++;
        }
    int cm{}, cs{};
    for (auto [pr, v] : mpm) cm += v * (v - 1) / 2;
    for (auto [pr, v] : mps) cs += v * (v - 1) / 2;
    cout << cs - cm << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}