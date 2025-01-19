#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    vector<double> p(n);
    for (int i = 0; i < n; ++ i) cin >> p[i], p[i] /= 100;
    vector<double> f(n + 1, 0.0l);
    f[0] = 1.0;
    for (int i = 0; i < n; ++ i) {
        for (int j = n; j > 0; -- j) f[j] = (1 - p[i]) * f[j] + p[i] * f[j - 1];
        f[0] *= (1 - p[i]);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}