#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, X, Y; cin >> n >> X >> Y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++ i) cin >> a[i] >> b[i];
    vector dp(n + 1, vector(n + 1, vector<int> (X + 1, inf)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++ i) 
        for (int j = 0; j <= i; ++ j) 
            for (int k = 0; k <= X; ++ k) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                if (k + a[i] <= X) {
                    dp[i + 1][j + 1][k + a[i]] = min(dp[i + 1][j + 1][k + a[i]], dp[i][j][k] + b[i]);
                }
            }
    for (int i = n - 1; i >= 0; -- i)
        for (int j = 0; j <= X; ++ j)
            if (dp[n][i][j] <= Y) {cout << min(i + 1, n) << "\n"; return;}
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}