#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<double> p(1 << n, 0.0);
    for (int i{}; i < (1 << n); ++ i) {
        double a, b; cin >> a >> b;
        p[i] = a * a + b * b;
    }
    for (int j{}; j < n; ++ j) {
        double p0{}, p1{};
        for (int i{}; i < (1 << i); ++ i)
            if (i & (1 << j)) p1 += p[j];
            else p0 += p[j];
        cout << fixed << setprecision(9) << p0 << " " << p1 << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}