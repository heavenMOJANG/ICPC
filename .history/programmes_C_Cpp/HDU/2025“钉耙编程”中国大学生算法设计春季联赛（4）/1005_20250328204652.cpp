#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    double P; int n, k; cin >> P >> n >> k;
    vector<double> D, R;
    for (int i = 0; i < n; ++ i) {
        int t; double p; cin >> t >> p;
        if (t == 0) D.emplace_back(p);
        else R.emplace_back(p);
    }
    sort(D.begin(), D.end());
    sort(R.begin(), R.end(), greater<double>());
    vector<double> prd(D.size() + 1, 1.0l), prr(R.size() + 1, 0.0l);
    for (int i = 1; i <= D.size(); ++ i) prd[i] = prd[i - 1] * (D[i - 1] / 10.0);
    for (int i = 1; i <= R.size(); ++ i) prr[i] = prr[i - 1] + R[i - 1];
    double ans = P;
    for (int i{}; i <= k; ++ i) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}