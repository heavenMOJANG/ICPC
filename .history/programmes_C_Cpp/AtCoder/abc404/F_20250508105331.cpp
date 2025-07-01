#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, T, M, K; cin >> N >> T >> M >> K;
    vector dp(T + 1, vector<double> (T * M + 1));
    for (int i{}; i <= T * M; ++ i) dp[T][i] = i >= K ? 1.0l: 0.0l;
    int maxn = min(N, M);
    for (int t = T - 1; ~t; -- t) {
        for (int k{}; k <= t * M; ++ k) {
            double best = 0, base = dp[t + 1][k];
            for (int n = 1; n <= maxn; ++ n) {
                static double ndp[31][31 * 30 + 1];
                int maxs = N;
                for (int i{}; i <= n; ++ i)
                    for (int s{}; s <= maxs; ++ s) ndp[i][s] = -1e18;
                ndp[0][0] = 0;
                for (int i = 1; i <= n; ++ i)
                    for (int s{}; s <= maxs; ++ s) {
                        if (ndp[i - 1][s] < -1e17) continue;
                        for (int c = 1; c + s <= maxs; ++ c) {
                            double con = dp[t + 1][k + c];
                            ndp[i][s + c] = max(ndp[i][s + c], ndp[i - 1][s] + con);
                        }
                    }
                double p = ndp[n][M];
                double val = (p + (double)(N - n) * base) / (double)N;
                best = max(best, val);
            }
            dp[t][k] = best;
        }
    }
    cout << fixed << setprecision(15) << dp[0][0] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}