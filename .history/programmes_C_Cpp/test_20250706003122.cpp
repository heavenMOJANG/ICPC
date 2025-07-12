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
        int n; ll m;
        cin >> n >> m;

        // dp[k]    = 考虑完上一步（i-1），恰用了 k 个 token 的所有方案权重之和
        // sumP[k]  = 对应这些方案，已用掉 token 标签之和 × 方案权重 的累加
        vector<ll> dp(n+1, 0), sumP(n+1, 0);
        vector<ll> ndp(n+1, 0), nsumP(n+1, 0);

        dp[0] = 1;    // 还没开始，空方案，权重 1
        sumP[0] = 0;  // 已用标签和 0

        ll prefixSum = 0;  // 用来维护 ∑_{p=1..i} p  mod m
        for(int i = 1; i <= n; i++){
            prefixSum = (prefixSum + i) % m;

            // 清零下一个状态
            fill(ndp.begin(),    ndp.end(),    0);
            fill(nsumP.begin(),  nsumP.end(),  0);

            for(int k = 0; k < i; k++){
                ll ways = dp[k];
                if(ways == 0 && sumP[k] == 0) continue;

                // —— 跳过 a_i = 0：
                //    匹配数 k 不变，sumP 也不变
                ndp[k]     = (ndp[k]    + ways)    % m;
                nsumP[k]   = (nsumP[k]  + sumP[k]) % m;

                // —— 进行一次匹配 a_i ≠ 0：
                //    当前所有“自由 token”p 的加权和
                //      = ∑_{p free} p × (当前方案权重)
                //      = prefixSum*ways - sumP[k]
                ll freeSum = (prefixSum * ways % m - sumP[k] + m) % m;

                //    1) 新的匹配数 k+1，对应的 dp 加上 freeSum
                ndp[k+1]   = (ndp[k+1]   + freeSum) % m;

                //    2) 更新 sumP：新用掉的标签和 = 旧 sumP + p，
                //       对所有 p 求和就是 sumP[k] + freeSum
                nsumP[k+1] = (nsumP[k+1] + sumP[k] + freeSum) % m;
            }

            // 滚动到下一步
            dp.swap(ndp);
            sumP.swap(nsumP);
        }

        // 答案 = ∑_{k=0..n} dp[k]
        ll ans = 0;
        for(int k = 0; k <= n; k++){
            ans = (ans + dp[k]) % m;
        }
        cout << ans << "\n";
    }

    return 0;
}
