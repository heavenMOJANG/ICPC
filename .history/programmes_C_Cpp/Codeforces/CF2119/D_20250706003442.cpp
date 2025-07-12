#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> dp(n+1), ndp(n+1);
    dp[0] = 1;
    for(int i = n; i >= 1; -- i){
        fill(ndp.begin(), ndp.end(), 0LL);
        for(int k = 0; k <= n; ++ k){
            if (!dp[k]) continue;
            ndp[k] = (ndp[k] + dp[k]) % m;
            int res = n - i + 1 - k;
            if(res > 0){
                    int add = dp[k];
                    add = add * i % m;
                    add = add * res % m;
                    ndp[k+1] = (ndp[k+1] + add) % m;
            }
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for(int k = 0; k <= n; ++ k) ans = (ans + dp[k]) % m;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}