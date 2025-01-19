#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 55000, mod = 998244353;
int n, x, m, dp[1010][N + 10], fib[25];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> x >> m;
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 24; ++ i) fib[i] = fib[i - 1] + fib[i - 2];
    vector<int> ndp(N + 1, inf);
    ndp[0] = 0;
    for (int i = 0; i <= N; ++ i)
        for (int j = 1; j <= 24; ++ j)
            if (i + fib[j] <= N) ndp[i + fib[j]] = min(ndp[i + fib[j]], ndp[i] + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= x; ++ i)
        for (int j = 1; j <= n; ++ j)
            for (int k = fib[i]; k <= N; ++ k)
                dp[j][k] = (dp[j][k] + dp[j - 1][k - fib[i]]) % mod;
    int ans = 0;
    for (int i = 0; i <= N; ++ i)
        if (ndp[i] == m) ans = (ans + dp[n][i]) % mod;
    cout << ans << "\n";
    return 0;
}