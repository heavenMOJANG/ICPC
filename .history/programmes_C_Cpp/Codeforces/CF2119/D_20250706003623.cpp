#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> dp(n+1), ndp(n+1);
    dp[0] = 1;
    for(int i = n; i; -- i){
        fill(ndp.begin(), ndp.end(), 0ll);
        for(int j = 0; j <= n; ++ j){
            if (!dp[j]) continue;
            ndp[j] = (ndp[j] + dp[j]) % m;
            int res = n - i + 1 - j;
            if(res > 0){
                int s = dp[j] * i % m * res % m;;
                ndp[j + 1] = (ndp[j + 1] + s) % m;
            }
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for(int i{}; i <= n; ++ i) ans = (ans + dp[i]) % m;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}