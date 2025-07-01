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
            
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}