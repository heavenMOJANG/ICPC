#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N), B = A;
    for (int i{}; i < N; ++ i) cin >> A[i] >> B[i];
    vector dp(K + 1, vector<int> (2, -INF));
    dp[0][0] = 0;
    for (int i{}; i < N; ++ i) {
        vector ndp(K + 1, vector<int> (2, -INF));
        for (int j{}; j <= K; ++ j) {
            if (dp[j][0] != -INF) ndp[j][0] = max(ndp[j][0], dp[j][0] + A[i]);
            if (dp[j][1] != -INF) ndp[j][1] = max(ndp[j][0], dp[j][1] + A[i]);
            if (dp[j][1] != -INF) ndp[j][1] = max(ndp[j][1], dp[j][1] + B[i]);
            if (j && dp[j - 1][0] != -INF ) ndp[j][1] = max(ndp[j][1], dp[j - 1][0] + B[i]);
        }
        dp.swap(ndp);
    }
    int ans{-INF};
    for (int j{}; j <= K; ++ j) ans = max({ans, dp[j][0], dp[j][1]});
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}