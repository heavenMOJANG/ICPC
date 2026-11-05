#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    int K{accumulate(A.begin(), A.end(), 0ll) / M};
    int n{1ll << N};
    vector<int> sum(n), dp(n);
    for (int s : views::iota(1, n)) {
        int i{countr_zero((unsigned)s)};
        sum[s] = sum[s ^ (1ll << i)] + A[i];
        for (int t{s}; t; t &= t - 1) {
            int j{countr_zero((unsigned)t)};
            dp[s] = max(dp[s], dp[s ^ (1ll << j)]);
        }
        dp[s] += (sum[s] % K == 0);
    }
    cout << M - dp[n - 1] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}