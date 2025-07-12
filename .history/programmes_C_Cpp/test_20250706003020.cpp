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

        // dp[k]   = 用前 i 步、恰好做了 k 次删除的方案总数
        // sumP[k] = 上面这些方案里，被删除的 token 标签之和的「加权累加」，
        //           用来在做第 i 步时快速算出“当前所有未删 token 的标签和”
        vector<ll> dp(n+1, 0), ndp(n+1);
        vector<ll> sumP(n+1, 0), nsumP(n+1);

        dp[0] = 1;      // 还没开始，空方案
        sumP[0] = 0;    // 没有删除，所以已用标签和为 0

        // 维护前缀和 1+2+...+i
        ll prefixSum = 0;
        for(int i = 1; i <= n; i++){
            prefixSum = (prefixSum + i) % m;

            // 清零下一行
            fill(ndp.begin(),   ndp.end(),   0);
            fill(nsumP.begin(), nsumP.end(), 0);

            // 枚举“之前做了 j 次删除”
            for(int j = 0; j < i; j++){
                if(dp[j] == 0 && sumP[j] == 0) continue;

                // 此刻：所有方案权重和 = dp[j]
                //        已用标签和的累加 = sumP[j]

                // 1) 选择 a_i = 0，不删
                //    次数不变，已用标签和也不变
                ndp[j]     = (ndp[j]     + dp[j])   % m;
                nsumP[j]   = (nsumP[j]   + sumP[j]) % m;

                // 2) 选择 a_i != 0，要删一个 token
                //    首先算出“当前所有未删 token 的标签和”：
                //      = (1+…+i) - (已用标签和)
                ll freeSum = (prefixSum - sumP[j]) % m;
                if(freeSum < 0) freeSum += m;

                //    把这 freeSum *当作*本步“选择不同 token”的一次性累加
                //    注意：freeSum = ∑_{p 未删} p，但我们这里只关心“有多少选择”
                //    由于 f(a) 只是计数，不带 p 的乘积，所以这里直接加 freeSum
                ndp[j+1]   = (ndp[j+1]   + freeSum) % m;

                //    接着，我们要更新“已用标签和的累加”：
                //    删除 p 之后，新的已用标签和 = oldUsedSum + p。 
                //    对所有 p 求和，再乘上对应的方案数，就是：
                //      sumP[j] * (number of free tokens)
                //          + dp[j] * (∑ p)
                //    其中“number of free tokens” = i - j
                ll cntFree = (i - j);
                ll addSumP = ( sumP[j] * cntFree % m
                             + dp[j] * freeSum % m ) % m;
                nsumP[j+1] = (nsumP[j+1] + addSumP) % m;
            }

            // 滚动
            dp.swap(ndp);
            sumP.swap(nsumP);
        }

        // 答案 = ∑_{j=0..n} dp[j]
        ll ans = 0;
        for(int j = 0; j <= n; j++){
            ans = (ans + dp[j]) % m;
        }
        cout << ans << "\n";
    }

    return 0;
}
