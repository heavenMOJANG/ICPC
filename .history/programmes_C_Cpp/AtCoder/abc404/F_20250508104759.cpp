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
    vector dp(t + 1, vector<double> (t * m + 1));
    for (int i{}; i <= t * m; ++ i) dp[t][i] = i >= k ? 1.0l: 0.0l;
    int maxn = min(n, m);
    for (int i{}; )
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}