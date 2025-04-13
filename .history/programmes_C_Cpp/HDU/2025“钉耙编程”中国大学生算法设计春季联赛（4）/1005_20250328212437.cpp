#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e4 + 10;
double P;
int n, k, D[N], R[N], lend = 1, lenr = 1;
double prd[N], prr[N];
void solve() {
    double P; int n, k; cin >> P >> n >> k;
    vector<int> D, R;
    for (int i = 0; i < n; ++ i) {
        int t; double p; cin >> t >> p;
        if (t == 0) D[lend ++] = p;
        else R[lenr ++] = p;
    }
    sort(D + 1, D + lend);
    sort(R + 1, R + lenr, greater<int>());
    vector<double> prd(lend + 1, 1.0), prr(lenr + 1, 0.0);
    for (int i = 1; i <= lend; ++ i) prd[i] = prd[i - 1] * (D[i - 1] / 10.0);
    for (int i = 1; i <= lenr; ++ i) prr[i] = prr[i - 1] + R[i - 1] * 1.0;
    double ans = P;
    for (int i{}; i <= k; ++ i) {
        if (i > lend) continue;
        int t = k - i;
        if (t > lenr) continue;
        double tmp = max(0.0, P * prd[i] - prr[t]);
        ans = min(ans, tmp);
    }
    cout << fixed << setprecision(2) << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}