#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k, l; cin >> n >> k >> l;
    double K = k, L = l;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    double T = a[0], lst{}, S{};
    for (int i = 1; i < n; ++ i) {
        double cur = min(L, min(a[i] + T, max(lst + K, (a[i] - T + lst + K) / 2.0)));
        T += max(0.0, cur - lst - K);
        S += min(K, cur - lst);
        lst = cur;
    }
    S += min(K, L - lst);
    cout << (int)round(2 * (L - S + a[0])) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}