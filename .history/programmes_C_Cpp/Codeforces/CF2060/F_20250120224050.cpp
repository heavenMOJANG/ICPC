#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 1e5 + 10;
constexpr int D = 20;
int dp[D][N];
void solve() {
    int n, d; cin >> n >> d;
    cout << d << " ";
    for (int i = 2; i <= n; ++ i) {
        int res{};
        int c = (d + 1) * d / 2;
        c %= MOD;
        function <int(int, int)> fastPow = [&](int a, int x) {
            int res = 1;
            while (x) {
                if (x & 1) (res *= a) %= MOD;
                (a *= a) %= MOD;
                x >>= 1;
            }
            return res;
        };
        function <int(int)> inv = [&](int x) { return fastPow(x, MOD - 2); };
        for (int j = 1; j < min(D, d); ++ j) {
            (res += c * dp[j][i]) %= MOD;
            (c *= d - j) %= MOD;
            (c *= inv(j + 2)) %= MOD;
        }
        cout << res << " \n"[i == n];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    for (int i = 1; i < N; ++ i) dp[1][i] = 1;
    for (int i = 2; i < D; ++ i)
        for (int j = 1; j < N; ++ j)
            for (int k = 2; k * k <= j; ++ k) {
                (dp[i][j] += dp[i - 1][k]) %= MOD;
                if (j / k != k) (dp[i][j] += dp[i - 1][j / k]) %= MOD;
            }
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}