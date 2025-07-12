#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        ll m;
        cin >> n >> m;

        // dp[k]: 只用 tokens i+1..n，匹配了 k 个的加权和
        vector<ll> dp(n+1), ndp(n+1);
        dp[0] = 1;

        // 从大到小枚举 token i
        for(int i = n; i >= 1; --i){
            fill(ndp.begin(), ndp.end(), 0LL);
            for(int k = 0; k <= n; ++k){
                if(!dp[k]) continue;
                // 1) 不匹配 token i
                ndp[k] = (ndp[k] + dp[k]) % m;
                // 2) 匹配 token i -> 增加一次匹配数
                //   可用 step 数 = (n-i+1) - k
                ll freeSteps = (ll)(n - i + 1) - k;
                if(freeSteps > 0){
                    ll add = dp[k];
                    add = add * i % m;
                    add = add * freeSteps % m;
                    ndp[k+1] = (ndp[k+1] + add) % m;
                }
            }
            dp.swap(ndp);
        }

        // 答案 = sum_{k=0..n} dp[k]
        ll ans = 0;
        for(int k = 0; k <= n; ++k){
            ans = (ans + dp[k]) % m;
        }
        cout << ans << "\n";
    }
    return 0;
}
