#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct pairHash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto h1 = hash<T1> {} (p.first);
        auto h2 = hash<T2> {} (p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i{}; i < n; ++ i) cin >> x[i] >> y[i];
    unordered_map<pair<int, int>, int, pairHash> mps, mpm;
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