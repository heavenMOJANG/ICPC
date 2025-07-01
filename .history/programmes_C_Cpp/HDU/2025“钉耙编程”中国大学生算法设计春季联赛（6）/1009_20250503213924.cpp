#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
int p5[N];
void solve() {
    int n, k;
    vector dp(n + 1, vector<int> (2, 0));
    vector<int> pre(n + 1, 0);
    dp[0][0] = 1; dp[0][1] = 0;
    pre[0] = p5[n];
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        int l = max(0ll, i - k), r = i - 1;
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    p5[0] = 1;
    for (int i = 1; i < N; ++ i) p5[i] = p5[i - 1] * 5 % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}